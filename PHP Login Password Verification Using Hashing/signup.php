<?php
  error_reporting(0);
?>




<?php
  $successalert=false;
  $erroralert=false;
  $ualert=false;
  if($_SERVER["REQUEST_METHOD"]=="POST" && isset($_POST['upload'])){
    require 'C:\xampp\htdocs\PHP_Course\Login System Project\partials\_DatabaseConnect.php';
    $uname=$_POST['email'];
    $pass=$_POST['password'];
    $conf=$_POST['cpassword'];
    $name=$_POST['name'];
    $pin=$_POST['pin'];
    $blood=$_POST['blood'];
    $image = $_FILES['image']['name'];
    $tmp_name = $_FILES['image']['tmp_name'];
    $allowed_extensions = array('jpg', 'jpeg', 'png', 'gif');
    $file_extension = pathinfo($image, PATHINFO_EXTENSION);
    if (!in_array($file_extension, $allowed_extensions)) {
        echo "Invalid file format. Only JPG, JPEG, PNG, and GIF images are allowed.";
    }
    else {
        // Upload the image to a directory
        $upload_path = "images/";
        $target_file = $upload_path . basename($image);
        if (move_uploaded_file($tmp_name, $target_file)) {
            $existssql="SELECT * FROM `user_table` WHERE Username='$uname'";
            $res=mysqli_query($conn,$existssql);
            $existnum=mysqli_num_rows($res);
            if($existnum>0){
              $ualert='Username Already Exists';
            }
            else{
              if($pass==$conf){
                  $hash=password_hash($pass,PASSWORD_DEFAULT);
                  $sql="INSERT INTO `user_table` (`S_NO`, `Username`, `Name`, `Pin Code`, `Blood Group`, `Image`, `Password`, `Time`) VALUES (NULL, '$uname', '$name', '$pin', '$blood', '$target_file', '$hash', current_timestamp())";
                  $res=mysqli_query($conn,$sql);
                  if($res){
                      $successalert=true;

                    }
                }
                else{
                    $erroralert=true;
                  }
     }
    // Insert image information into the database
     
     
     //here server ends
    }
  }
}
?>


<!doctype html>
<html lang="en">
  <head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.0.0/dist/css/bootstrap.min.css" integrity="sha384-Gn5384xqQ1aoWXA+058RXPxPg6fy4IWvTNh0E263XmFcJlSAwiGgFAW/dAiS6JXm" crossorigin="anonymous">

    <title>Sign Up Here</title>
  </head>
  <body>
  <?php require 'C:\xampp\htdocs\PHP_Course\Login System Project\partials\_navbar.php'; ?>
  <?php
      if($successalert){
        echo '<div class="alert alert-success alert-dismissible fade show" role="alert">
        <strong>Success!</strong>Data Is Taken Successfully You Can Log In.
        <button type="button" class="close" data-dismiss="alert" aria-label="Close">
        <span aria-hidden="true">&times;</span>
        </button>
        </div>';
      }
      if($erroralert){
        echo '<div class="alert alert-danger alert-dismissible fade show" role="alert">
        <strong>Error!</strong> Passwords Do not match Please Try Again!.
        <button type="button" class="close" data-dismiss="alert" aria-label="Close">
        <span aria-hidden="true">&times;</span>
        </button>
        </div>';
      }
      if($ualert){
        echo '<div class="alert alert-danger alert-dismissible fade show" role="alert">
        <strong>Error! </strong>'.$ualert.'
        <button type="button" class="close" data-dismiss="alert" aria-label="Close">
        <span aria-hidden="true">&times;</span>
        </button>
        </div>';
      }

  ?>
  <h2 class='text-center my-4'>SignUp To Our Website</h2>
  <div class="container my-4"style="display:flex;align-items:center;justify-content:center; flex-direction:column;">
    
    <form action="/PHP_Course/Login System Project/signup.php" method='post' enctype="multipart/form-data">
  <div class="form-group">
    <label for="email">Email address</label>
    <input type="email" maxlength="30" class="form-control" id="email" name="email" aria-describedby="emailHelp" placeholder="Enter email" required>
  </div>
  <div class="form-group">
    <label for="name">Your Full Name</label>
    <input type="text" maxlength="30" class="form-control" id="name" name="name" placeholder="Name" required>
  </div>
  <div class="form-group">
    <label for="pin">Your Pin Code Number</label>
    <input type="number" maxlength="30" class="form-control" id="pin" name="pin" placeholder="Pin-Code" required>
  </div>
  <div class="form-group">
    <label for="exampleFormControlSelect1">Your Blood Group</label>
    <select class="form-control" id="blood" name="blood">
      <option value="value" selected>Select Your Blood</option>
      <option>A+</option>
      <option>A-</option>
      <option>B+</option>
      <option>B-</option>
      <option>O+</option>
      <option>O-</option>
      <option>AB+</option>
      <option>AB-</option>
    </select>
  </div>
  <div class="form-group">
    <label for="photo">Upload Your Photo</label>
    <input type="file" class="form-control-file" name="image" id="image">
  </div>
  <div class="form-group">
    <label for="password">Password</label>
    <input type="password" maxlength="30" class="form-control" id="password" name="password" placeholder="Password" required>
  </div>
  <div class="form-group">
    <label for="cpassword">Confirm Password</label>
    <input type="password" class="form-control" id="cpassword" name="cpassword" placeholder="Confirm Password">
    <small id="emailHelp" class="form-text text-muted">Make Sure You Have Enter The Same Password</small>
  </div>
  <button type="submit" name="upload" class="btn btn-primary text-center">Submit</button>
  <button type="reset" class="btn btn-primary ml-8">Reset</button>
</form>
  </div>

    <!-- Optional JavaScript -->
    <!-- jQuery first, then Popper.js, then Bootstrap JS -->
    <script src="https://code.jquery.com/jquery-3.2.1.slim.min.js" integrity="sha384-KJ3o2DKtIkvYIK3UENzmM7KCkRr/rE9/Qpg6aAZGJwFDMVNA/GpGFF93hXpG5KkN" crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/popper.js@1.12.9/dist/umd/popper.min.js" integrity="sha384-ApNbgh9B+Y1QKtv3Rn7W3mgPxhU9K/ScQsAP7hUibX39j7fakFPskvXusvfa0b4Q" crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@4.0.0/dist/js/bootstrap.min.js" integrity="sha384-JZR6Spejh4U02d8jOt6vLEHfe/JQGiRRSQQxSfFWpi1MquVdAyjUar5+76PVCmYl" crossorigin="anonymous"></script>
  </body>
</html>

