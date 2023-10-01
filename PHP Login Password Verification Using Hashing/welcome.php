<?php
  session_start();
  if(!isset($_SESSION['loggedin']) || ($_SESSION['loggedin']!=true)){
    header("location: login.php");
    exit;
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

    <title>Welcome <?php echo $_SESSION['name']?></title>
  </head>
  <body>

<!--View Modal -->
<div class="modal fade" id="viewmodal" tabindex="-1" aria-labelledby="exampleModalLabel" aria-hidden="true">
  <div class="modal-dialog">
    <div class="modal-content">
      <div class="modal-header">
        <h5 class="modal-title" id="viewModalLabel">View Profile</h5>
        <button type="button" class="close" data-dismiss="modal" aria-label="Close">
          <span aria-hidden="true">&times;</span>
        </button>
      </div>
      <div class="modal-body container">
        <?php
          $servername='localhost';
          $username='root';
          $password='';
          $database='users_database';
      
          $conn=mysqli_connect($servername,$username,$password,$database);
      
          if(!$conn){
              die("The Database Has A Connection Problem Due To This Error:- ".mysqli_connect_error());
          }
          else{
            $a=$_SESSION['username'];
            $sqlq="SELECT * FROM `user_table` WHERE Username='$a'";
            $result=mysqli_query($conn,$sqlq);
            while($row=mysqli_fetch_assoc($result)){
              echo '
              <div class="card" style="width: 18rem;">
              <img src="'.$row['Image'].'" class="card-img-top" alt="...">
              <div class="card-body">
                <h5 class="card-title">'.$row['Name'].'</h5>
                <p class="card-text">Some quick example text to build on the card title and make up the bulk of the cards content.</p>
                <a href="#" class="btn btn-primary">Go somewhere</a>
              </div>
            </div>';
            }
          }
        ?>
      </div>
      <div class="modal-footer">
        <button type="button" class="btn btn-secondary" data-dismiss="modal">Close</button>
      </div>
    </div>
  </div>
</div>

  <?php require 'C:\xampp\htdocs\PHP_Course\Login System Project\partials\_navbar.php'; ?>
    <div class="container my-4">
      <div class="jumbotron">
        <h1 class="display-4">Welcome <?php echo $_SESSION['name']?></h1>
        <p class="lead">Hope You Are Well This Is Your Account Click On The Logout Button When You Are Done!</p>
        <hr class="my-4">
        <p>The Time And Date Is <?php echo date('d-m-y h:i:s');?></p>
        <a class="btn btn-primary btn-lg" href="\PHP_Course\Login System Project\logout.php" role="button">Log Out</a>
        <button class="btn btn-primary btn-lg" id="view"  role="button">View Profile</button>
        <button class="btn btn-primary btn-lg"  role="button">Update Profile</button>
      </div>
    </div>
    <script src="https://code.jquery.com/jquery-3.2.1.slim.min.js" integrity="sha384-KJ3o2DKtIkvYIK3UENzmM7KCkRr/rE9/Qpg6aAZGJwFDMVNA/GpGFF93hXpG5KkN" crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/popper.js@1.12.9/dist/umd/popper.min.js" integrity="sha384-ApNbgh9B+Y1QKtv3Rn7W3mgPxhU9K/ScQsAP7hUibX39j7fakFPskvXusvfa0b4Q" crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@4.0.0/dist/js/bootstrap.min.js" integrity="sha384-JZR6Spejh4U02d8jOt6vLEHfe/JQGiRRSQQxSfFWpi1MquVdAyjUar5+76PVCmYl" crossorigin="anonymous"></script>
    <script>
      let a=document.getElementById('view');
      a.addEventListener('click',(element)=>{
        console.log(element);
        $('#viewmodal').modal('toggle')
      })
    </script>
  </body>
</html>
