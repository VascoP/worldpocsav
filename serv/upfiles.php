<?php
if ($_FILES["file"]["error"] == 0)
{
	if(move_uploaded_file($_FILES["file"]["tmp_name"], "upload/" . $_FILES["file"]["name"]))
		echo "Ok";
}
?>

