import os
import time
from PIL import Image
import numpy as np
import tensorflow as tf
import tensorflow_hub as hub
import matplotlib.pyplot as plt

# Set environment variable for TensorFlow Hub download progress
os.environ["TFHUB_DOWNLOAD_PROGRESS"] = "True"

# Download the image file
!wget "https://user-images.githubusercontent.com/12981474/40157448-eff91f06-5953-11e8-9a37-f6b5693fa03f.png" -O input_image.png

# Constants
IMAGE_FILE_PATH = "input_image.png"
MODEL_PATH = "https://tfhub.dev/captain-pool/esrgan-tf2/1"

def prepare_image(file_path):
  """ Load image from path and preprocess it to make it model ready """
  high_res_img = tf.image.decode_image(tf.io.read_file(file_path))
  
  # If PNG, remove the alpha channel. The model only supports images with 3 color channels.
  if high_res_img.shape[-1] == 4:
    high_res_img = high_res_img[...,:-1]
  
  high_res_size = (tf.convert_to_tensor(high_res_img.shape[:-1]) // 4) * 4
  high_res_img = tf.image.crop_to_bounding_box(high_res_img, 0, 0, high_res_size[0], high_res_size[1])
  high_res_img = tf.cast(high_res_img, tf.float32)
  
  return tf.expand_dims(high_res_img, 0)

def store_image(image_tensor, filename):
  """
    Saves unscaled Tensor Images.
    Args:
      image_tensor: 3D image tensor. [height, width, channels]
      filename: Name of the file to save.
  """
  if not isinstance(image_tensor, Image.Image):
    image_tensor = tf.clip_by_value(image_tensor, 0, 255)
    image_tensor = Image.fromarray(tf.cast(image_tensor, tf.uint8).numpy())
  
  image_tensor.save("%s.jpg" % filename)
  print("Saved as %s.jpg" % filename)

def display_image(image_tensor, title=""):
  """
    Plots images from image tensors.
    Args:
      image_tensor: 3D image tensor. [height, width, channels].
      title: Title to display in the plot.
  """
  image_array = np.asarray(image_tensor)
  image_array = tf.clip_by_value(image_array, 0, 255)
  
  display_image = Image.fromarray(tf.cast(image_array, tf.uint8).numpy())
  
  plt.imshow(display_image)
  plt.axis("off")
  plt.title(title)

# Preprocess the image
high_res_image = prepare_image(IMAGE_FILE_PATH)

# Plotting Original Resolution image
display_image(tf.squeeze(high_res_image), title="Original Image")
store_image(tf.squeeze(high_res_image), filename="Original_Image")

# Load the pre-trained model from TensorFlow Hub
pretrained_model = hub.load(MODEL_PATH)

# Time the model prediction
start_time = time.time()
generated_image = pretrained_model(high_res_image)
generated_image = tf.squeeze(generated_image)

print("Time Taken: %f" % (time.time() - start_time))

# Plotting Super Resolution Image
display_image(tf.squeeze(generated_image), title="Super Resolution")
store_image(tf.squeeze(generated_image), filename="Super_Resolution")


# Set the figure size
plt.rcParams['figure.figsize'] = [15, 10]

# Create subplots
fig, axes = plt.subplots(1, 3)
fig.tight_layout()

# Plot original image
plt.subplot(131)
display_image(tf.squeeze(high_res_image), title="Original")

# Plot low resolution image
plt.subplot(132)
fig.tight_layout()
display_image(tf.squeeze(low_res_image), "x4 Bicubic")

# Plot super resolution image
plt.subplot(133)
fig.tight_layout()
display_image(tf.squeeze(generated_image), "Super Resolution")

# Save the figure
plt.savefig("ESRGAN_DIV2K.jpg", bbox_inches="tight")

# Print PSNR value
print("PSNR: %f" % psnr)
