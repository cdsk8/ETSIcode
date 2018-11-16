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
	  $palabras = StringSplit($lines[$j]," "
   Next
   ;_ArrayDisplay($lines)

Next



Func sumar($txt)
   $txt = StringUpper($txt)
   $encontrado = -1
   For $i = 0 To UBound($palabras)-1
	  If $palabras[$i] = $txt Then
		 $encontrado = $i
		 Break
	  EndIf
   Next
   If $encontrado = -1 Then
	  ReDim $palabras[UBound($palabras)+1]
	  ReDim $ocurrencias[UBound($ocurrencias)+1]
	  $palabras[UBound($palabras)+1-1] = $txt
	  $ocurrencias[UBound($ocurrencias)+1-1] = 1
   Else
	  $ocurrencias[$encontrado] += 1
   EndIf
EndFunc
