### Web Ministryplace

- hint : Let's read this website in the language of Alines. Or maybe not?

#### Write UP

- Analyze the index.php file, it has a function called str_replace.
- the include function directly displays the file without validation.
- Now the problem is it replace "../" with ''.
- So, if we pass .../, we will get the path .
- Similarly, we can encode the string ../../flag => .../...//../flag
- And voila - CHTB{b4d_4li3n_pr0gr4m1ng}
