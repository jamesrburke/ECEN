<?php
$server="127.0.0.1";
$user="root";
$pass="";
$db="tester";	
$link=mysqli_connect($server, $user, $pass, $db);
  if(!$link)
    {echo mysqli_error($link);
     echo "<br><br>";
    }
	$result=mysqli_query($link, "SELECT * FROM `test` ORDER BY `Name` DESC");
?>

<html>
   <head>
      <title>Data</title>
   </head>
<body>
   <h1>Test Data</h1>

   <table border="1" cellspacing="1" cellpadding="1">
		<tr>
			<td>&nbsp;Name 1&nbsp;</td>
			<td>&nbsp;Number 1&nbsp;</td>
		</tr>

      <?php 
		  if($result!==FALSE){
		     while($row = mysqli_fetch_array($result)) {
		        printf("<tr><td> &nbsp;%s&nbsp; </td><td> &nbsp;%s&nbsp; </td></tr>", 
		           $row["Name"], $row["Number"]);
		     }
		     mysqli_free_result($result);
		     mysqli_close($link);
		  }
      ?>

   </table>
</body>
</html>
