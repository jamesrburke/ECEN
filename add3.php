<?php
$server="127.0.0.1";
$user="root";
$pass="";
$db="tester";
?>


<html>
<head>
<title>Test for uploading data</title>
</head>
<body>

<?php
if(!empty($_GET['name1']))
{
  $name1=$_GET['name1'];
  $num1=$_GET['num1'];
  $link=mysqli_connect($server, $user, $pass, $db);
  if(!$link)
    {echo mysqli_error();
     echo "<br><br>";
    }
  
  $query = "INSERT INTO `test` (`Name`, `Number`) VALUES ('$name1', '$num1');";

  if(!mysqli_query($link, $query))
    {echo mysqli_error($link);
     echo "<br><br>";
    }

  mysqli_close($link);
}

?>

<form action="add3.php" method="get">
value for name1<br>
<input type="text" name="name1"><br><br>
value for num1<br>
<input type="text" name="num1"><br><br>
<input type="submit"><br>
</form>
</body>
</html>