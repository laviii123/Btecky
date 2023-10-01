<?php
  $successalert=false;
  $erroralert=false;
  if($_SERVER["REQUEST_METHOD"]=='POST'){
    require 'C:\xampp\htdocs\PHP_Course\Login System Project\partials\_DatabaseConnect.php';
    $uname=$_POST['email'];
    $pass=$_POST['password'];
    //$sql="SELECT * FROM `user_table` WHERE Username='$uname' AND Password= '$pass'";
    $sql="SELECT * FROM `user_table` WHERE Username='$uname'";
    $res=mysqli_query($conn,$sql);
    $num=mysqli_num_rows($res);
    if($num==1){
      while($row=mysqli_fetch_assoc($res)){
        if(password_verify($pass,$row['Password'])){
          $successalert=true;
          session_start();
          $_SESSION['loggedin']=true;
          $_SESSION['username']=$uname;
          header("location: welcome.php");
        }
        else{
          $erroralert='Invalid Username Or Password!';
        }
      }
    }
    else{
      $erroralert='Invalid Username Or Password!';
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

    <title>Login Here</title>
  </head>
  <body>
  <?php require 'C:\xampp\htdocs\PHP_Course\Login System Project\partials\_navbar.php'; ?>
  <?php
      if($successalert){
        echo '<div class="alert alert-success alert-dismissible fade show" role="alert">
        <strong>Success!</strong>Login Successful.
        <button type="button" class="close" data-dismiss="alert" aria-label="Close">
        <span aria-hidden="true">&times;</span>
        </button>
        </div>';
      }
      if($erroralert){
        echo '<div class="alert alert-danger alert-dismissible fade show" role="alert">
        <strong>Error!</strong>'.$erroralert.'
        <button type="button" class="close" data-dismiss="alert" aria-label="Close">
        <span aria-hidden="true">&times;</span>
        </button>
        </div>';
      }

  ?>
  <h2 class='text-center my-4'>Login To Your Account</h2>
  <div class="container my-4"style="display:flex;align-items:center;justify-content:center; flex-direction:column;">
    
    <form action="/PHP_Course/Login System Project/login.php" method='post'>
  <div class="form-group">
    <label for="email">Email address</label>
    <input type="email" class="form-control" id="email" name="email" aria-describedby="emailHelp" placeholder="Enter email">
  </div>
  <div class="form-group">
    <label for="password">Password</label>
    <input type="password" class="form-control" id="password" name="password" placeholder="Password">
  </div>
  <button type="submit" class="btn btn-primary text-center">Log In</button>
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