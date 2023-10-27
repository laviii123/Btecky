import qrcode
import os

def generate_qr_code(data, filename):
    qr = qrcode.QRCode(
        version=1,
        error_correction=qrcode.constants.ERROR_CORRECT_M,
        box_size=10,
        border=4,
    )
    qr.add_data(data)
    qr.make(fit=True)

    img = qr.make_image(fill_color="black", back_color="white")
    os.makedirs("out", exist_ok=True)
    i = 1
    while True:
        filename = f"{filename_prefix}{i}.png"
        filepath = os.path.join("out", filename)
        if not os.path.exists(filepath):
            break
        i += 1
    img.save(filepath)
    print(f"A QR code has been generated and saved at out/ as `{filename}'")



# Example usage
data = input("URL: ")
filename_prefix = "qr"
generate_qr_code(data, filename_prefix)
