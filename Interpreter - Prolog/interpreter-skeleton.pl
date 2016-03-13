:- [tokenizer].

run(InputFile,OutputFile):-
	tokenize(InputFile,Program),
	parse(ParseTree,Program,[]),
	evaluate(ParseTree,[],VariablesOut), 
	output_result(OutputFile,ParseTree,VariablesOut).

output_result(OutputFile,ParseTree,Variables):- 
	open(OutputFile,write,OutputStream),
	write(OutputStream,'PARSE TREE:'), 
	nl(OutputStream), 
	writeln_term(OutputStream,0,ParseTree),
	nl(OutputStream), 
	write(OutputStream,'EVALUATION:'), 
	nl(OutputStream), 
	write_list(OutputStream,Variables), 
	close(OutputStream).
	
writeln_term(Stream,Tabs,int(X)):-
	write_tabs(Stream,Tabs), 
	writeln(Stream,int(X)).
writeln_term(Stream,Tabs,ident(X)):-
	write_tabs(Stream,Tabs), 
	writeln(Stream,ident(X)).
writeln_term(Stream,Tabs,Term):-
	functor(Term,_Functor,0), !,
	write_tabs(Stream,Tabs),
	writeln(Stream,Term).
writeln_term(Stream,Tabs1,Term):-
	functor(Term,Functor,Arity),
	write_tabs(Stream,Tabs1),
	writeln(Stream,Functor),
	Tabs2 is Tabs1 + 1,
	writeln_args(Stream,Tabs2,Term,1,Arity).
	
writeln_args(Stream,Tabs,Term,N,N):-
	arg(N,Term,Arg),
	writeln_term(Stream,Tabs,Arg).
writeln_args(Stream,Tabs,Term,N1,M):-
	arg(N1,Term,Arg),
	writeln_term(Stream,Tabs,Arg), 
	N2 is N1 + 1,
	writeln_args(Stream,Tabs,Term,N2,M).
	
write_tabs(_,0).
write_tabs(Stream,Num1):-
	write(Stream,'\t'),
	Num2 is Num1 - 1,
	write_tabs(Stream,Num2).

writeln(Stream,Term):-
	write(Stream,Term), 
	nl(Stream).
	
write_list(_Stream,[]). 
write_list(Stream,[Ident = Value|Vars]):-
	write(Stream,Ident),
	write(Stream,' = '),
	format(Stream,'~1f',Value), 
	nl(Stream), 
	write_list(Stream,Vars).

parse(ParseTree) --> assign(ParseTree).

assign(assignment(ID , assign_op , EX , semicolon)) --> id(ID) , equal , expr(EX) , semi.
id(ident(X)) --> [X] , {atom(X)}.
equal --> [=].
semi --> [;].

expr(expression(TE)) --> term(TE). 
expr(expression(TE , add_op , EX)) --> term(TE) , add , expr(EX).
expr(expression(TE , sub_op , EX)) --> term(TE) , sub , expr(EX).
add --> [+].
sub --> [-].

term(term(FA)) --> factor(FA).
term(term(FA, mult_op, TE)) --> factor(FA) , mult, term(TE).
term(term(FA , div_op , TE)) --> factor(FA) , div , term(TE).
mult --> [*].
div --> [/].

factor(factor(int(X))) --> [X] , {number(X)}.
factor(factor(left_paren , EX , right_paren)) --> left , expr(EX) , right.
left --> ['('].
right --> [')'].
	

evaluate(ParseTree, [], VariablesOut):-
	eval_assign(ParseTree, VariablesOut).
	
eval_assign(assignment(ID, assign_op, EX, semicolon), VariablesOut):-
	eval_id(ID, IdResult),
	eval_expr(EX, ExprResult),
	VariablesOut = [IdResult = ExprResult].

eval_id(ident(ID), IdResult):-
	IdResult = ID.

eval_expr(expression(TE), VariablesOut):-
	eval_term(TE, VariablesOut).
eval_expr(expression(TE, add_op, EX), VariablesOut):-
	eval_term(TE, TermResult),
	eval_expr(EX, ExprResult),
	VariablesOut is TermResult + ExprResult.
eval_expr(expression(TE, sub_op, EX), VariablesOut):-
	eval_term(TE, TermResult),
	eval_expr(EX, ExprResult),
	VariablesOut is TermResult - ExprResult.

eval_term(term(FA), VariablesOut):-
	eval_factor(FA, VariablesOut).
eval_term(term(FA, mult_op, TE), VariablesOut):-
	eval_factor(FA, FactorResult),
	eval_term(TE, TermResult),
	VariablesOut is FactorResult * TermResult.
eval_term(term(FA, div_op, TE), VariablesOut):-
	eval_factor(FA, FactorResult),
	eval_term(TE, TermResult),
	VariablesOut is FactorResult / TermResult.

eval_factor(factor(int(X)), VariablesOut):-
	VariablesOut is X.
eval_factor(factor(left_paren, EX, right_paren), VariablesOut):-
	eval_expr(EX, ExprResult),
	VariablesOut is ExprResult.