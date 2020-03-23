module Hw2 where

data ASTResult = ASTError String | ASTJust (String, String, Int) deriving (Show, Read)
data ASTDatum = ASTSimpleDatum String | ASTLetDatum String deriving (Show, Read)
data AST = EmptyAST | ASTNode ASTDatum AST AST deriving (Show, Read)

isNumber :: String -> Bool
--Evaluation :: AST -> ASTResult
normalEvaluation :: AST -> ASTResult
-- DO NOT MODIFY OR DELETE THE LINES ABOVE -- 
-- IMPLEMENT isNumber, Evaluation and normalEvaluation FUNCTIONS ACCORDING TO GIVEN SIGNATURES -- 
ops = ["plus","times","negate","num","len","str","cat"]

nums = ['0','1','2','3','4','5','6','7','8','9']
count=0


isNumber_1 :: String -> Bool
isNumber_1 (y:[]) = if elem y nums then True
                    else False 
isNumber_1 (y:ys) = if elem y nums then isNumber_1 ys
                    else False

isNumber "" = False
isNumber (x:[]) = if elem x nums then True 
                  else False
isNumber (x:xs) = if x=='-' && xs/=[] then isNumber_1 xs
                  else if elem x nums && isNumber_1 xs then True
                  else False

getError :: AST -> String
getError EmptyAST = ""
getError (ASTNode (ASTSimpleDatum val) EmptyAST EmptyAST) = ""
getError (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum val) EmptyAST EmptyAST) EmptyAST) = if (isNumber val)==False then "the value '"++val++"' is not a number!" else ""
getError (ASTNode (ASTSimpleDatum op) lnode rnode)=
    let leftType   = getType lnode
        rightType  = getType rnode
    in case op of "plus"    -> if (leftType/="num" || rightType/="num") then "plus operation is not defined between " ++ leftType ++ " and " ++ rightType ++ "!" else ""
                  "times"   -> if (leftType/="num" || rightType/="num") then "times operation is not defined between " ++ leftType ++ " and " ++ rightType ++ "!" else ""
                  "negate"  -> if (leftType/="num")then "negate operation is not defined on " ++ leftType else ""
                  "len"     -> if (leftType/="str") then "len operation is not defined on " ++ leftType else ""
                  "cat"     -> if (leftType/="str" || rightType/="str") then "cat operation is not defined between " ++ leftType ++ " and " ++ rightType ++ "!" else ""
                  otherwise -> ""


getType :: AST -> String
getType (ASTNode (ASTSimpleDatum op) _ _) = if elem op ["plus","times","negate","num","len"] then "num" else "str"
--getType (ASTNode (ASTLetDatum op) lnode rnode) = getType rnode


normalEvaluation ast = if errr/="" then ASTError errr else ASTJust (result,typ,cnt)
    where
      ((result,typ,cnt),errr)= evaluation (((replaceFunc ast),"",0),"")  


evaluation ((input_AST@(ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum numval) EmptyAST EmptyAST) EmptyAST),a,count),err_)= if (getError input_AST)=="" then ((numval,a,count),err_) else ((numval,a,count),getError input_AST)
evaluation ((input_AST@(ASTNode (ASTSimpleDatum "str") (ASTNode (ASTSimpleDatum strval) EmptyAST EmptyAST) EmptyAST),a,count),err_)= ((strval,a,count),err_)
evaluation ((input_AST@(ASTNode (ASTSimpleDatum op) EmptyAST EmptyAST),a,count),err_) =  ((op,a,count),err_)
evaluation ((input_AST@(ASTNode (ASTSimpleDatum op) lnode rnode),a,count),err_) =
   let errLeft= getError lnode
       errRight = getError rnode
       ((leftExpressed,b,countLeft),leftERROR) = evaluation ((lnode,a,count),getError lnode) 
       ((rightExpressed,c,countRight),rightERROR) = evaluation ((rnode,a,count),getError rnode)
       typex = if elem op ["plus","times","negate","num","len"] then "num" else "str"
       error_= if errLeft=="" && errRight=="" then getError input_AST else if errLeft/="" then errLeft else if errLeft=="" && errRight/="" then errRight else err_
   in case op of "plus"   -> ((if error_/="" then "0" else (show (read leftExpressed + read rightExpressed)),typex,countRight+countLeft+count+1),error_)
                 "times"  -> ((if error_/="" then "0" else (show ((read leftExpressed) * (read rightExpressed))),typex,countRight+countLeft+count+1),error_)
                 "negate" -> ((if error_/="" then "0" else (show (-(read leftExpressed))),typex,countLeft+count+1),error_)
                 "num"    -> ((if error_/="" then "0" else (read leftExpressed),typex,count),error_)
                 "len"    -> ((if error_/="" then "0" else (show (length(leftExpressed))),typex,countLeft+count+1),error_)
                 "str"    -> ((if error_/="" then "0" else (read leftExpressed),typex,count),error_)
                 "cat"    -> ((if error_/="" then "0" else leftExpressed ++ rightExpressed,typex,countRight+countLeft+count+1),error_)


replaceFunc ast= replaceFunc2 ast []
replaceFunc2 EmptyAST varlist=EmptyAST
replaceFunc2 raw@(ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum val) EmptyAST EmptyAST) EmptyAST) varlist= raw
replaceFunc2 raw@(ASTNode (ASTSimpleDatum "str") (ASTNode (ASTSimpleDatum val) EmptyAST EmptyAST) EmptyAST) varlist= raw
replaceFunc2 raw@(ASTNode (ASTSimpleDatum "len") (ASTNode (ASTSimpleDatum "num") val EmptyAST) EmptyAST) varlist=raw
replaceFunc2 raw@(ASTNode (ASTSimpleDatum "len") (ASTNode (ASTSimpleDatum "str") val EmptyAST) EmptyAST) varlist=raw
replaceFunc2 raw@(ASTNode (ASTSimpleDatum "negate") (ASTNode (ASTSimpleDatum "num") val EmptyAST) EmptyAST) varlist=raw
replaceFunc2 raw@(ASTNode (ASTSimpleDatum "negate") (ASTNode (ASTSimpleDatum "str") val EmptyAST) EmptyAST) varlist=raw
replaceFunc2 variable@(ASTNode (ASTSimpleDatum op) EmptyAST EmptyAST) varlist = giveExpression variable varlist
replaceFunc2 (ASTNode (ASTLetDatum op) lnode rnode) varlist = replaceFunc2 rnode (replaceFunc3 lnode varlist)
replaceFunc2 (ASTNode (ASTSimpleDatum op) lnode rnode) varlist=
    let leftExpressed = replaceFunc2 lnode varlist
        rightExpressed= replaceFunc2 rnode varlist
    in (ASTNode (ASTSimpleDatum op) leftExpressed rightExpressed)


replaceFunc3 (ASTNode (ASTLetDatum op) lnode rnode) varlist = replaceFunc2 rnode (local_Global_func (op,lnode) varlist False)

local_Global_func (op,input) [] wehave= if wehave then [] else [(op,input)]
local_Global_func (op,input) ((op_in,arg_in):xs) wehave = if op==op_in then (op,input):(local_Global_func (op,input) xs True) else (op_in,arg_in):(local_Global_func (op,input) xs wehave)

giveExpression variable_in@(ASTNode (ASTSimpleDatum op1) EmptyAST EmptyAST) ((op_in,arg_in):xs) = if op1==op_in then arg_in else variable_in
