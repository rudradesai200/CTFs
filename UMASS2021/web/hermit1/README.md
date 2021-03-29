#### Solution

- When you visited the URL given, it asked us to upload an image. Also, the hint in the problem said, "how do you know if the uploaded file is an image".
- Now, I tried uploading a dummy image, and checked what it does.
- When you upload an image, it just saved it to some location on the server and then gave you an url to view that image.
- When you click that image, it directly printed the content in to the html page with some php script.
- So, basically, we have to create a php script, which can execute on the server and show us the flag.
- Using some available answers on web, I created the script, which takes a command as an input using a form, and whenever submitted, it will run that command on the server's terminal using php shell_exec funtion.
- Now, the only thing remaining to figure out was to find the flag.
- So, I listed home directory and found the flag.txt file.
- I printed the content and voila!! Got the flag.
