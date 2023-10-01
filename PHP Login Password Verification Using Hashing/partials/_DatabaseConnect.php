<?php
    $servername='localhost';
    $username='root';
    $password='';
    $database='users_database';

    $conn=mysqli_connect($servername,$username,$password,$database);

    if(!$conn){
        die("The Database Has A Connection Problem Due To This Error:- ".mysqli_connect_error());
    }
?>