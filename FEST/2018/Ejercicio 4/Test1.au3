#include <File.au3>
#include <Array.au3>

;$archivos = _FileListToArray("src\","*.ASM",1)
$archivos = _FileListToArray("src\","CHKDSK.ASM",1,True)
;_ArrayDisplay($archivos)
Global $palabras[0]
Global $ocurrencias[0]

For $i = 1 To $archivos[0]
   $lines = StringSplit(FileRead($archivos[$i]),@CRLF)
   For $j = 1 To $lines[0]
	  If StringInStr($lines[$j],";") = 0 Then
		 $lines[$j] = ""
	  Else
		 $lines[$j] =StringTrimLeft($lines[$j],StringInStr($lines[$j],";"))
	  EndIf
	  $partes = dividir($lines[$j])
	  ;_ArrayDisplay($partes)
	  For $k = 1 To $partes[0]
		 sumar($partes[$k])
	  Next
   Next
   ;_ArrayDisplay($lines)

Next

ConsoleWrite("MOST: "&getMost()&@CRLF)

#cs
For $i = 0 To UBound($palabras)-1
   ConsoleWrite($palabras[$i]&"  "&$ocurrencias[$i]&@CRLF)
Next
#ce

Func dividir($linea)
   Local $palabras[1]

   $n = 0
   $tmp = ""
   For $i = 0 To StringLen($linea)
	  $c = StringMid($linea,$i,1)
	  If StringIsAlpha($c) Then
		 $tmp &= $c
	  Else
		 If $tmp Then
			ReDim $palabras[UBound($palabras)+1]
			$palabras[UBound($palabras)-1] = $tmp
			$tmp = ""
			$n += 1
		 EndIf
	  EndIf
   Next

   $palabras[0] = $n
   Return $palabras
EndFunc

Func getMost()
   $max = 0
   $top = 0
   For $i = 0 To UBound($palabras)-1
	  If $ocurrencias[$i] > $max Then
		 $max = $ocurrencias[$i]
		 $top = $i
	  EndIf
   Next
   Return $palabras[$top]&"  "&$ocurrencias[$top]
EndFunc
Func sumar($txt)
   $txt = StringUpper($txt)
   $encontrado = -1
   For $i = 0 To UBound($palabras)-1
	  If $palabras[$i] = $txt Then
		 $encontrado = $i
		 ExitLoop
	  EndIf
   Next
   If $encontrado = -1 Then
	  ReDim $palabras[UBound($palabras)+1]
	  ReDim $ocurrencias[UBound($ocurrencias)+1]
	  $palabras[UBound($palabras)-1] = $txt
	  $ocurrencias[UBound($ocurrencias)-1] = 1
   Else
	  $ocurrencias[$encontrado] += 1
   EndIf
EndFunc
