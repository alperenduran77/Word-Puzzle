#include<stdio.h>
#include<string.h>

#define MAX_ROW 100  
#define MAX_COLUMN 250
#define MAX_WORD_LENGTH 10

             /* Function definitions    */
int Search(char* searchword,char board[MAX_ROW][MAX_COLUMN],int row_counter);
int SearchSouth(char *searchword,char board[MAX_ROW][MAX_COLUMN],int number_of_rows);
int SearchEast(char *searchword,char board[MAX_ROW][MAX_COLUMN],int number_of_rows);
int SearchNorth(char *searchword,char board[MAX_ROW][MAX_COLUMN],int number_of_rows);
int SearchWest(char *searchword,char board[MAX_ROW][MAX_COLUMN],int number_of_rows);
int SearchSouthEast(char *searchword,char board[MAX_ROW][MAX_COLUMN],int number_of_rows);
int SearchSouthWest(char *searchword,char board[MAX_ROW][MAX_COLUMN],int number_of_rows);
int SearchNorthEast(char *searchword,char board[MAX_ROW][MAX_COLUMN],int number_of_rows);
int SearchNorthWest(char *searchword,char board[MAX_ROW][MAX_COLUMN],int number_of_rows);

int main()
{
	char words[MAX_WORD_LENGTH];  /* words[MAX_WORD_LENGTH] -> variable to hold words */
	char board[MAX_ROW][MAX_COLUMN];  /* board[MAX_ROW][MAX_COLUMN] -> char array to hold puzzle */
	int row_counter=0; /* variable to hold puzzles row number */
	
	FILE *input1;
	FILE *input2;

    input1 = fopen("input1.txt","r");
	input2 = fopen("input2.txt", "r");

    while(fscanf(input2,"%s ",board[row_counter]) != EOF) /* reads puzzle till end of file and counts row number */
	{  
		 row_counter=row_counter+1;
	}  
	
	while(fscanf(input1,"%s",words) != EOF) /* reads word one by one till end of file */
	{
     Search(words,board,row_counter); /* it sends words to search function */
	}
	
	return 0;
}


int Search(char* searchword,char board[MAX_ROW][MAX_COLUMN],int row_counter)
{				
 SearchSouth(searchword,board,row_counter);
 SearchEast(searchword,board,row_counter);
 SearchNorth(searchword,board,row_counter);
 SearchWest(searchword,board,row_counter);
 SearchSouthEast(searchword,board,row_counter);
 SearchSouthWest(searchword,board,row_counter);
 SearchNorthEast(searchword,board,row_counter);
 SearchNorthWest(searchword,board,row_counter);
	return 0;
}

int SearchSouth(char *searchword,char board[MAX_ROW][MAX_COLUMN],int number_of_rows)  /* ↓(S) */
{
	int row=0,column=0,first_index=0,word_length,index=0,tempx; 
	word_length=strlen(searchword); /* to use later found words length */
	char findword[word_length]; /* temporary variable to compare strings */
	FILE *output=fopen("output.txt","a");
	while(row<number_of_rows) /* searchs till last row */
	{
		while(board[row][column]!='\0') /* searchs till see null character */
		{ 
			if(searchword[first_index]==board[row][column]) /* if first letter of word matches it searchs south direction */
			{
				tempx=row; /* to hold first occurance we assign current row to temporary variable */
				while(word_length>index) /* searchs till length of word */
				{
				findword[index]=board[row][column]; /* assigns founded letter on the puzzle to temporary variable */
				row++; /* to search south direction increments row number */
				index++; /* increments temporary variables index to compare lettter by letter */		
				}	
				row=tempx;	/* get back first occurance */
				
				if(strcmp(searchword,findword) == 0) /* if strings match it prints word,coordinates and direction */
				{
					fprintf(output,"%s (%d,%d) S\n",findword,row+1,column+1);
				}
			
				findword[0]='\0';                /* temporary variables are reset to be used again  */
				findword[word_length]='\0';
				index=0;

				}
			column++;
		}
		row++;
		column=0;
	}

	return 0;
}
int SearchEast(char *searchword,char board[MAX_ROW][MAX_COLUMN],int number_of_rows)  /* →(E) */
{
	int row=0,column=0,first_index=0,word_length,index=0,tempy; 
	word_length=strlen(searchword); /* to use later found words length */
	char findword[word_length]; /* temporary variable to compare strings */
	FILE *output=fopen("output.txt","a");
	while(row<number_of_rows) /* searchs till last row */
	{
		while(board[row][column]!='\0') /* searchs till see null character */
		{
			if(searchword[first_index]==board[row][column]) /* if first letter of word matches it searchs east direction */
			{
				tempy=column; /* to hold first occurance we assign current column to temporary variable */
				while(word_length>index)
				{
				findword[index]=board[row][column]; /* assigns founded letter on the puzzle to temporary variable */
				column++; /* to search east direction increments column number */
				index++;  /* increments temporary variables index to compare lettter by letter */		
				}	
				column=tempy;	/* get back first occurance */
				
				if(strcmp(searchword,findword) == 0) /* if strings match it prints words,coordinates and direction */
				{
					fprintf(output,"%s (%d,%d) E\n",findword,row+1,column+1);
				}
			
				findword[0]='\0';             /* temporary variables are reset to be used again  */
				findword[word_length]='\0';
				index=0;
				
				}
			column++;
		}
		row++;
	    column=0;
	}

	return 0;
}
int SearchNorth(char *searchword,char board[MAX_ROW][MAX_COLUMN],int number_of_rows) /* ↑(N) */
{
	int row=0,column=0,first_index=0,word_length,index=0,tempx; 
	word_length=strlen(searchword); /* to use later found words length */
	char findword[word_length]; /* temporary variable to compare strings */
	FILE *output=fopen("output.txt","a");
	while(row<number_of_rows) /* searchs till last row */
	{
		while(board[row][column]!='\0') /* searchs till see null character */
		{ 
			if(searchword[first_index]==board[row][column]) /* if first letter of word matches it searchs north direction */
			{
				tempx=row; /* to hold first occurance we assign current row to temporary variable */
				while(word_length>index)
				{
				findword[index]=board[row][column]; /* assigns founded letter on the puzzle to temporary variable */
				row--; /* to search north direction decrements column number */
				index++; /* increments temporary variables index to compare lettter by letter */		
				}	
				row=tempx;	/* get back first occurance */
				
				if(strcmp(searchword,findword)==0) /* if strings match it prints words,coordinates and direction */
				{
					fprintf(output,"%s (%d,%d) N\n",findword,row+1,column+1);
				}
			
				findword[0]='\0';        /* temporary variables are reset to be used again  */
				findword[word_length]='\0';
				index=0;
				}
			column++;
		}
		row++;
		column=0;
	}

	return 0;
}
int SearchWest(char *searchword,char board[MAX_ROW][MAX_COLUMN],int number_of_rows) /* ←(W) */
{
	int row=0,column=0,first_index=0,word_length,index=0,tempy; 
	word_length=strlen(searchword);  /* to use later found words length */
	char findword[word_length]; /* temporary variable to compare strings */
	FILE *output=fopen("output.txt","a");
	while(row<number_of_rows) /* searchs till last row */
	{
		while(board[row][column]!='\0') /* searchs till see null character */
		{ 
			if(searchword[first_index]==board[row][column]) /* if first letter of word matches it searchs west direction */
			{
				tempy=column; /* to hold first occurance we assign current column to temporary variable */
				while(word_length>index)
				{
				findword[index]=board[row][column]; /* assigns founded letter on the puzzle to temporary variable */
				column--; /* to search west direction decrements column number */
				index++;  /* increments temporary variables index to compare lettter by letter */		
				}	
				column=tempy; /* get back first occurance */
				
				if(strcmp(searchword,findword)==0) /* if strings match it prints words,coordinates and direction */
				{
					fprintf(output,"%s (%d,%d) W\n",findword,row+1,column+1);	
				}
			
				findword[0]='\0';         /* temporary variables are reset to be used again  */
				findword[word_length]='\0';
				index=0;
				}
			column++;
		}
		row++;
		column=0;
	}

	return 0;
}
int SearchSouthEast(char *searchword,char board[MAX_ROW][MAX_COLUMN],int number_of_rows) /* ↘(SE) */
{
	int row=0,column=0,first_index=0,word_length,index=0,tempx,tempy; 
	word_length=strlen(searchword); /* to use later found words length */
	char findword[word_length]; /* temporary variable to compare strings */
	FILE *output=fopen("output.txt","a");
	while(row<number_of_rows) /* searchs till last row */
	{
		while(board[row][column]!='\0') /* searchs till see null character */
		{ 
			if(searchword[first_index]==board[row][column]) /* if first letter of word matches it searchs southeast direction */
			{
				tempx=row;   /* to hold first occurance we assign current row to temporary variable */
				tempy=column; /* to hold first occurance we assign current column to temporary variable */
				while(word_length>index)
				{
				findword[index]=board[row][column]; /* assigns founded letter on the puzzle to temporary variable */
				row++;  /* to search southeast direction increments row number */
				column++; /* to search southeast direction increments column number */
				index++; /* increments temporary variables index to compare lettter by letter */		
				}	
				row=tempx;	/* get back first occurance */
				column=tempy; /* get back first occurance */
				
				if(strcmp(searchword,findword)==0) /* if strings match it prints words,coordinates and direction */
				{
					fprintf(output,"%s (%d,%d) SE\n",findword,row+1,column+1);
				}
			      
				findword[0]='\0';  /* temporary variables are reset to be used again  */
				findword[word_length]='\0';
				index=0;
				}
			column++;
		}
		row++;
		column=0;
	}

	return 0;
}
int SearchSouthWest(char *searchword,char board[MAX_ROW][MAX_COLUMN],int number_of_rows) /* ↙(SW) */
{
	int row=0,column=0,first_index=0,word_length,index=0,tempx,tempy;   	  
	word_length=strlen(searchword); /* to use later found words length */
	char findword[word_length]; /* temporary variable to compare strings */
	FILE *output=fopen("output.txt","a");
	while(row<number_of_rows) /* searchs till last row */
	{
		while(board[row][column]!='\0') /* searchs till see null character */
		{ 
			if(searchword[first_index]==board[row][column]) /* if first letter of word matches it searchs southwest direction */
			{
				tempx=row; /* to hold first occurance we assign current row to temporary variable */
				tempy=column; /* to hold first occurance we assign current column to temporary variable */
				while(word_length>index)
				{
				findword[index]=board[row][column]; /* assigns founded letter on the puzzle to temporary variable */
				row++; /* to search southwest direction increments row number */
				column--; /* to search southwest direction decrementts row number */
				index++;	/* increments temporary variables index to compare lettter by letter */	
				}	
				row=tempx;  /* get back first occurance */
				column=tempy;  /* get back first occurance */
				
				if(strcmp(searchword,findword)==0) /* if strings match it prints words,coordinates and direction */
				{
					fprintf(output,"%s (%d,%d) SW\n",findword,row+1,column+1);	
				}
			      
				findword[0]='\0';                 /* temporary variables are reset to be used again  */
				findword[word_length]='\0';
				index=0;
				}
			column++;
		}
		row++;
		column=0;
	}

	return 0;
}
int SearchNorthEast(char *searchword,char board[MAX_ROW][MAX_COLUMN],int number_of_rows) /* ↗(NE) */
{
	int row=0,column=0,first_index=0,word_length,index=0,tempx,tempy; 
	word_length=strlen(searchword); /* to use later found words length */
	char findword[word_length];  /* temporary variable to compare strings */
	FILE *output=fopen("output.txt","a");
	while(row<number_of_rows) /* searchs till last row */
	{
		while(board[row][column]!='\0') /* searchs till see null character */
		{ 
			if(searchword[first_index]==board[row][column]) /* if first letter of word matches it searchs northeast direction */
			{
				tempx=row; /* to hold first occurance we assign current row to temporary variable */
				tempy=column; /* to hold first occurance we assign current column to temporary variable */
				while(word_length>index)
				{
				findword[index]=board[row][column]; /* assigns founded letter on the puzzle to temporary variable */
				row--; /* to search northeast direction decrements row number */
				column++; /* to search northeast direction incrementts column number */
				index++;  /* increments temporary variables index to compare lettter by letter */	
				}	
				row=tempx;	/* get back first occurance */
				column=tempy; /* get back first occurance */

				if(strcmp(searchword,findword)==0) /* if strings match it prints words,coordinates and direction */
				{
					fprintf(output,"%s (%d,%d) NE\n",findword,row+1,column+1);
				}
			      
				findword[0]='\0'; /* temporary variables are reset to be used again  */
				findword[word_length]='\0';
				index=0;
				}
			column++;
		}
		row++;
		column=0;
	}

	return 0;
}
int SearchNorthWest(char *searchword,char board[MAX_ROW][MAX_COLUMN],int number_of_rows) /* ↙(NW) */
{
	int row=0,column=0,first_index=0,word_length,index=0,tempx,tempy; 
	word_length=strlen(searchword);  /* to use later found words length */
	char findword[word_length]; /* temporary variable to compare strings */
	FILE *output=fopen("output.txt","a");
	while(row<number_of_rows) /* searchs till last row */
	{
		while(board[row][column]!='\0') /* searchs till see null character */
		{ 
			if(searchword[first_index]==board[row][column]) /* if first letter of word matches it searchs northwest direction */
			{
				tempx=row; /* to hold first occurance we assign current row to temporary variable */
				tempy=column; /* to hold first occurance we assign current row to temporary variable */
				while(word_length>index)
				{
				findword[index]=board[row][column]; /* assigns founded letter on the puzzle to temporary variable */
				row--; /* to search northwest direction decrements row number */
				column--; /* to search northwest direction decrements column number */
				index++;	 /* increments temporary variables index to compare lettter by letter */	
				}	
				row=tempx;	/* get back first occurance */
				column=tempy; /* get back first occurance */

				if(strcmp(searchword,findword)==0) /* if strings match it prints words,coordinates and direction */
				{
					fprintf(output,"%s (%d,%d) NW\n",findword,row+1,column+1);
				}
			      
				findword[0]='\0';  /* temporary variables are reset to be used again  */
				findword[word_length]='\0';
				index=0;
				}
			column++;
		}
		row++;
		column=0;
	}

	return 0;
}