@echo on
echo generating
chcp 65001
cd %~dp0
java -jar antlr-3.5.2-complete.jar -Dlanguage=C -report MyGram.g
echo generated
