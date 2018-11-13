$cantidad = 0
For $i =0 To 1000
   If Mod($i,8)=0 or Mod($i,9)=0 or Mod($i,2)=0 or Mod($i,3)=0 Then $cantidad += 1
Next
ConsoleWrite($cantidad&@CRLF)