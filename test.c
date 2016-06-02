/* Martianov Sergei 02.06.2016
Multiplication table with parameters */

#include <stdio.h>
#include <stdlib.h>

int main( void )
{
  int x, y, i, j;
  char *query;

  query = getenv("QUERY_STRING");
  if (sscanf(query, "x=%d&y=%d", &x, &y) != 2)
  	x = y = 1;

  if (x < 0)
  	x *= -1;
  if (y < 0)
  	y *= -1;

  printf("Content-Type: text/html;\n\n");

  printf("<html><head><title>Test</title><meta charset='utf-8' /></head><body>"
  	"<form><label for='x'>X:</label> <input type='text' name='x' value='%d' /> "
  	"<label for='x'>Y:</label> <input type='text' name='y' value='%d' /> "
  	"<input type='submit' value='Считать' /></form><table>", x, y);

  for (j = 1; j <= y; j++)
  {
  	printf("<tr>");
  	for (i = 1; i <= x; i++)
  	  printf("<td>%d</td>", i * j);
  	printf("</tr>");
  }

  printf("</table></body></html>");
  
  return 1;
}