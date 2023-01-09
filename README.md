# get_next_line

get_next_line es una función que lee una línea de un descriptor de archivo y la devuelve como una cadena. Aquí hay un esquema simple de cómo puede escribir una función get_next_line:

- Cree un búfer para almacenar los datos que lee del descriptor de archivo.
- Cree un bucle que lea datos del descriptor de archivo en el búfer hasta que se encuentre un carácter de nueva línea (\n) o se alcance el final del archivo.
* Si se encuentra un carácter de nueva línea, puede dividir el búfer en el carácter de nueva línea y devolver la parte anterior a la nueva línea como la línea que se leyó. Si se llega al final del archivo, puede devolver el contenido del búfer como la línea que se leyó.
- Después de devolver la línea, puede restablecer el búfer y volver al paso 2 para leer la siguiente línea.
