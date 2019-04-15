<?php
    include 'config.php';
    $data=mysqli_query($db,"SELECT * FROM led WHERE id=".$_GET['id']);
    if($val=mysqli_fetch_array($data)){
        echo "led".$val['val'];
    }
?>