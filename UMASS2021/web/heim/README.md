#### Solution

- "Modern auth for the modern viking"
- The hint said "Make sure you sniff before you sign. There are open-source tools to help with both".
- I simply opened the link given and gave my name. It returned an access token.
- But, the strange thing was to figure out where to access the token.
- So, I followed the hint and started sniffing the connection using wireshark
- In one of the TCP packet response, I found the word JWT (which refer's to JSON Web Tokens).
- I researched on this and figured out that they are a form of bearer tokens.
- I should have understood it earlier as the link said, that "Only those who BEARER a token may enter"
- Now, I fired up postman, and tried to hit the server with a GET request and with the access token as authorization of BEARER token type.
- The server responded with an encoded msg.
- The strange thing I noticed was that it contained many char groups, "ICAg"
- I searched on web about this and found that "ICAg" represents space in Base64 encoding.
- I decoded the message with a base64 decoder and the msg represented the response for a OPTIONS header.
- This was the decoded message
  ```
  {
    "api": {
        "v1": {
            "/auth": {
                "get": {
                    "summary": "Debugging method for authorization post",
                    "security": "None",
                    "parameters": {
                        "access_token": {
                            "required": true,
                            "description": "Access token from recently authorized Viking",
                            "in": "path",
                        },
                        "jwt_secret_key": {
                            "required": false,
                            "description": "Debugging - should be removed in prod Heim",
                            "in": "path"
                        }
                    }
                },
                "post": {
                    "summary": "Authorize yourself as a Viking",
                    "security": "None",
                    "parameters": {
                        "username": {
                            "required": true,
                            "description": "Your Viking name",
                            "in": "body",
                            "content": "multipart/x-www-form-urlencoded"
                        }
                    }
                }
            },
            "/heim": {
                "get": {
                    "summary": "List the endpoints available to named Vikings",
                    "security": "BearerAuth"
                }
            },
            "/flag": {
                "get": {
                    "summary": "Retrieve the flag",
                    "security": "BearerAuth"
                }
            }
        }
    }
  }
  ```
- As you can see the flag can be retrieved by a GET request on /flag and with the bearerAuth.
- So, I tried the same, it responded with another msg - "You are not worthy. Only the AllFather Odin may view the flag"
- I started the whole process by giving Odin as the name. It worked and gave me the flag - "UMASS{liveheim_laughheim_loveheim}"
