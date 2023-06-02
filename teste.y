
void operacao(string $$, string $1, string $2, string $2){
    if(tabelaSimbolos.find($1.label) == tabelaSimbolos.end() && tabelaSimbolos.find($3.label) == tabelaSimbolos.end()){
        if($1.tipo == "int" && $3.tipo == "float"){
            $1.tipo = "float";
            $$.label = genTemp();
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + $1.tipo + ")" + $1.label + ";\n";
            $$.declaracao = $1.declaracao + $3.declaracao + "\t" + $1.tipo + " " + $$.label + ";\n";

            string aux = $$.label;

            $$.label = genTemp();
            $$.tipo = "float";

            $$.traducao += "\t" + $$.label + " = " + aux + " + " + $3.label + ";\n";
            $$.declaracao += "\t" + $1.tipo + " " + $$.label + ";\n";
        }
        else if($1.tipo == "float" && $3.tipo == "int"){
            $3.tipo = "float";
            $$.label = genTemp();
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + $3.tipo + ")" + $3.label + ";\n";
            $$.declaracao = $1.declaracao + $3.declaracao + "\t" + $1.tipo + " " + $$.label + ";\n";

            string aux = $$.label;

            $$.label = genTemp();
            $$.tipo = "float";

            $$.traducao += "\t" + $$.label + " = " + $1.label + " + " + aux + ";\n";
            $$.declaracao += "\t" + $1.tipo + " " + $$.label + ";\n";
        }
        //IGUAIS
        else {
            $$.label = genTemp();
            $$.tipo = $1.tipo;
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " + " + $3.label + ";\n";
            $$.declaracao = $1.declaracao + $3.declaracao +"\t" + $1.tipo + " " + $$.label + ";\n";
        }
    }
    //VAR NUMERO
    else if(!(tabelaSimbolos.find($1.label) == tabelaSimbolos.end()) && tabelaSimbolos.find($3.label) == tabelaSimbolos.end()){
        if(tabelaSimbolos[$1.label].tipo == "int" && $3.tipo == "float"){
            $$.label = genTemp();
            $$.tipo = "float";
            $$.declaracao = $1.declaracao + $3.declaracao + "\t" + $3.tipo + " " + $$.label + ";\n";
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + $3.tipo + ")" + tabelaSimbolos[$1.label].temp + ";\n";

            string aux = $$.label;
            
            $$.label = genTemp();
            $$.tipo = "float";

            $$.traducao += "\t" + $$.label + " = " + aux + " + " + $3.label + ";\n";
            $$.declaracao += "\t" + $3.tipo + " " + $$.label + ";\n";
    }
        else if(tabelaSimbolos[$1.label].tipo == "float" && $3.tipo == "int"){
            $3.tipo = "float";
            $$.label = genTemp();
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + $3.tipo + ")" + $3.label + ";\n";
            $$.declaracao = $1.declaracao + $3.declaracao + "\t" + $1.tipo + " " + $$.label + ";\n";

            string aux = $$.label;

            $$.label = genTemp();
            $$.tipo = "float";

            $$.traducao += "\t" + $$.label + " = " + tabelaSimbolos[$1.label].temp + " + " + aux + ";\n";
            $$.declaracao += "\t" + $1.tipo + " " + $$.label + ";\n";
        }
        //IGUAIS
        else {
            $$.label = genTemp();
            $$.tipo = tabelaSimbolos[$1.label].tipo;
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + tabelaSimbolos[$1.label].temp + " + " + $3.label + ";\n";
            $$.declaracao = $1.declaracao + $3.declaracao +"\t" + $1.tipo + " " + $$.label + ";\n";
        }
    }
    //NUMERO VAR/*
    else if(tabelaSimbolos.find($1.label) == tabelaSimbolos.end() && !(tabelaSimbolos.find($3.label) == tabelaSimbolos.end())){
        if($1.tipo == "int" && tabelaSimbolos[$3.label].tipo == "float"){
            $$.label = genTemp();
            $$.declaracao = $1.declaracao + $3.declaracao + "\t" + tabelaSimbolos[$3.label].tipo + " " + $$.label + ";\n";
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + tabelaSimbolos[$3.label].tipo+ ")" + $1.label + ";\n";

            string aux = $$.label;
            
            $$.label = genTemp();
            $$.tipo = "float";

            $$.traducao += "\t" + $$.label + " = " + aux + " + " + tabelaSimbolos[$3.label].temp + ";\n";
            $$.declaracao += "\t" + $3.tipo + " " + $$.label + ";\n";
        }
        else if($1.tipo == "float" && tabelaSimbolos[$3.label].tipo == "int"){
            $3.tipo = "float";
            $$.label = genTemp();
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + $1.tipo + ")" + tabelaSimbolos[$3.label].temp + ";\n";
            $$.declaracao = $1.declaracao + $3.declaracao + "\t" + $1.tipo + " " + $$.label + ";\n";

            string aux = $$.label;

            $$.label = genTemp();
            $$.tipo = "float";

            $$.traducao += "\t" + $$.label + " = " + $1.label + " + " + aux + ";\n";
            $$.declaracao += "\t" + $1.tipo + " " + $$.label + ";\n";
        }
    //IGUAIS
        else {
            $$.label = genTemp();
            $$.tipo = tabelaSimbolos[$3.label].tipo;
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " + " + tabelaSimbolos[$3.label].temp + ";\n";
            $$.declaracao = $1.declaracao + $3.declaracao +"\t" + $1.tipo + " " + $$.label + ";\n";
        }
    }
    //VAR VAR
    else if(!(tabelaSimbolos.find($1.label) == tabelaSimbolos.end() && tabelaSimbolos.find($3.label) == tabelaSimbolos.end())){
        if(tabelaSimbolos[$1.label].tipo  == "int" && tabelaSimbolos[$3.label].tipo == "float"){
            $$.label = genTemp();
            $$.declaracao = $1.declaracao + $3.declaracao + "\t" + tabelaSimbolos[$3.label].tipo + " " + $$.label + ";\n";
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + tabelaSimbolos[$3.label].tipo+ ")" +tabelaSimbolos[$1.label].temp + ";\n";

            string aux = $$.label;
            
            $$.label = genTemp();
            $$.tipo = "float";

            $$.traducao += "\t" + $$.label + " = " + aux + " + " + tabelaSimbolos[$3.label].temp + ";\n";
            $$.declaracao += "\t" + $3.tipo + " " + $$.label + ";\n";
        }
        else if(tabelaSimbolos[$1.label].tipo == "float" && tabelaSimbolos[$3.label].tipo == "int"){
            $3.tipo = "float";
            $$.label = genTemp();
            $$.tipo = "float";
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + tabelaSimbolos[$1.label].tipo + ")" + tabelaSimbolos[$3.label].temp + ";\n";
            $$.declaracao = $1.declaracao + $3.declaracao + "\t" + $1.tipo + " " + $$.label + ";\n";

            string aux = $$.label;

            $$.label = genTemp();
            $$.tipo = "float";

            $$.traducao += "\t" + $$.label + " = " + tabelaSimbolos[$1.label].temp + " + " + aux + ";\n";
            $$.declaracao += "\t" + $1.tipo + " " + $$.label + ";\n";
        }
        //IGUAIS
        else {
            $$.label = genTemp();
            $$.tipo = tabelaSimbolos[$1.label].tipo;
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + tabelaSimbolos[$1.label].temp + " + " + tabelaSimbolos[$3.label].temp + ";\n";
            $$.declaracao = $1.declaracao + $3.declaracao +"\t" + $1.tipo + " " + $$.label + ";\n";
        }
    }
}