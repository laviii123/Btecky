
<?php
  if(isset($_SESSION['loggedin']) && $_SESSION['loggedin']==true){
    $log=true;
  }
  else{
    $log=false;
  }

  echo '<nav class="navbar navbar-expand-lg navbar-light bg-light">
    <a class="navbar-brand" href="/PHP_Course/Login System Project">Authentication System</a>
    <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
      <span class="navbar-toggler-icon"></span>
    </button>
  
    <div class="collapse navbar-collapse" id="navbarSupportedContent">
      <ul class="navbar-nav mr-auto">
        <li class="nav-item active">
          <a class="nav-link" href="/PHP_Course/Login System Project/welcome.php">Home <span class="sr-only">(current)</span></a>
        </li>';
      if(!$log){
        echo '<li class="nav-item">
          <a class="nav-link" href="\PHP_Course\Login System Project\login.php">Log In</a>
        </li>
        <li class="nav-item">
          <a class="nav-link" href="\PHP_Course\Login System Project\signup.php">Sign Up</a>
        </li>';
      }
      if($log){
        echo '<li class="nav-item">
          <a class="nav-link" href="/PHP_Course/Login System Project/logout.php">Logout</a>
        </li>';
      }
      echo '</ul>
      <form class="form-inline my-2 my-lg-0">
        <input class="form-control mr-sm-2" type="search" placeholder="Search" aria-label="Search">
        <button class="btn btn-outline-success my-2 my-sm-0" type="submit">Search</button>
      </form>
    </div>
  </nav>';
?>