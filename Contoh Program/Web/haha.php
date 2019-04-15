<?php
	include "config.php";


	if(isset($_POST['someAct'])){
		mysqli_query($db,"UPDATE led SET val=1 WHERE id=1");
	}else{
		mysqli_query($db,"UPDATE led SET val=0 WHERE id=1");
	}
	header('location:Control.html');
?>