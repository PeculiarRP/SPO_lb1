

build:
	gcc -g -o ./app ./Main.c ANTLR/MyGramLexer.c ANTLR/MyGramParser.c ./TreeGenerator.c -lantlr3c  

clean:
	rm -f ./app

rebuild: clean build