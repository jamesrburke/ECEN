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
if(!empty($_GET['Lat']))
{
  $Lat=$_GET['Lat'];
  $Lng=$_GET['Lng'];
  $link=mysqli_connect($server, $user, $pass, $db);
  if(!$link)
    {echo mysqli_error();
     echo "<br><br>";
    }
  
  $query = "INSERT INTO `gps` (`Lat`, `Lng`) VALUES ('$Lat', '$Lng');";

  if(!mysqli_query($link, $query))
    {echo mysqli_error($link);
     echo "<br><br>";
    }

  mysqli_close($link);
}

?>

<form action="add4.php" method="get">
value for Lat<br>
<input type="text" name="Lat"><br><br>
value for Lng<br>
<input type="text" name="Lng"><br><br>
<input type="submit"><br>
</form>
</body>
</html>