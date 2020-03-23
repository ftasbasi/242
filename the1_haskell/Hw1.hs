module Hw1 where

type Mapping = [(String, String, String)]
data AST = EmptyAST | ASTNode String AST AST deriving (Show, Read)

writeExpression :: (AST, Mapping) -> String
evaluateAST :: (AST, Mapping) -> (AST, String)
-- DO NOT MODIFY OR DELETE THE LINES ABOVE -- 
-- IMPLEMENT writeExpression and evaluateAST FUNCTION ACCORDING TO GIVEN SIGNATURES -- 

writeExpression (x,y) = case getLetClause y of ""        ->  getExpression x
                                               otherwise ->  getLetClause y ++ getExpression x

evaluateAST (ast_,mapping_) = ( getExpression2 ast_ mapping_ , getEvaluation ast_ mapping_)

giveMapping :: Mapping -> String 
giveMapping []=""
giveMapping ((var_name,var_type,var_value):xs) = if var_type=="str" then var_name ++"=\""++var_value ++ "\"" ++ case giveMapping xs of ""        -> ""
                                                                                                                                       otherwise -> ";" ++ giveMapping xs
                                                 else var_name ++"="++var_value ++ case giveMapping xs of ""        -> ""
                                                                                                          otherwise -> ";" ++ giveMapping xs
                                                                                                         
getLetClause :: Mapping -> String
getLetClause [] = ""
getLetClause x = "let " ++ giveMapping x ++ " in "

giveRawValue :: AST -> String
giveRawValue (ASTNode rawType leftSide rightSide) = rawType


getExpression :: AST -> String
getExpression (EmptyAST) = ""
getExpression (ASTNode op EmptyAST EmptyAST) = op
getExpression (ASTNode op lnode rnode)=
    let leftExpressed = getExpression lnode
        rightExpressed = getExpression rnode
    in case op of "plus"    -> "(" ++ leftExpressed ++ "+" ++ rightExpressed ++ ")"
                  "times"   -> "(" ++ leftExpressed ++ "*" ++ rightExpressed ++ ")"
                  "cat"     -> "(" ++ leftExpressed ++ "++" ++ rightExpressed ++ ")"
                  "len"     -> "(length "++ leftExpressed ++ rightExpressed++")"
                  "negate"  -> "(-" ++ leftExpressed ++ rightExpressed++")"
                  "str"     -> "\"" ++ giveRawValue lnode ++ "\"" ++ rightExpressed
                  "num"     -> giveRawValue lnode ++ rightExpressed 
                  otherwise -> ""

getExpression2 :: AST -> Mapping -> AST
getExpression2 EmptyAST (a)=EmptyAST
getExpression2 (ASTNode op EmptyAST EmptyAST) (a) = checkVariableExist2 (ASTNode op EmptyAST EmptyAST) (a)
getExpression2 (ASTNode op lnode rnode) (a) =
    let leftExpressed = getExpression2 lnode (a)
        rightExpressed = getExpression2 rnode (a)
    in case op of "plus"    -> (ASTNode "plus" leftExpressed rightExpressed)
                  "times"   -> (ASTNode "times" leftExpressed rightExpressed)
                  "cat"     -> (ASTNode "cat" leftExpressed rightExpressed)
                  "len"     -> (ASTNode "len" leftExpressed rightExpressed)
                  "negate"  -> (ASTNode "negate" leftExpressed rightExpressed)
                  "str"     -> (ASTNode "str" leftExpressed rightExpressed)
                  "num"     -> (ASTNode "num" leftExpressed rightExpressed)


getEvaluation :: AST -> Mapping -> String
getEvaluation (ASTNode op lnode rnode) (a) = if a==[] then getEvaluation1 (ASTNode op lnode rnode) else getEvaluation2 (ASTNode op lnode rnode) (a)


getEvaluation1 :: AST -> String
getEvaluation1 (ASTNode op EmptyAST EmptyAST) = show op
getEvaluation1 (ASTNode op lnode rnode) =
    let leftExpressed = getEvaluation1 lnode
        rightExpressed = getEvaluation1 rnode
    in case op of "plus"   -> show ( read leftExpressed + read rightExpressed)
                  "times"  -> show ((read leftExpressed) * (read rightExpressed))
                  "negate" -> show (-(read leftExpressed))
                  "num"    -> read leftExpressed
                  "len"    -> show (length(leftExpressed))
                  "str"    -> read leftExpressed
                  "cat"    -> leftExpressed ++ rightExpressed

getEvaluation2 :: AST -> Mapping -> String
getEvaluation2 (ASTNode "num" (ASTNode op EmptyAST EmptyAST) EmptyAST) _ = op
getEvaluation2 (ASTNode "str" (ASTNode op EmptyAST EmptyAST) EmptyAST) _ = op
getEvaluation2 (ASTNode op EmptyAST EmptyAST) (a) = checkVariableExist (ASTNode op EmptyAST EmptyAST) (a)
getEvaluation2 (ASTNode op lnode rnode) (a) =
    let leftExpressed = getEvaluation2 lnode (a)
        rightExpressed = getEvaluation2 rnode (a)
    in case op of "plus"   -> show (read leftExpressed + read rightExpressed)
                  "times"  -> show ((read leftExpressed) * (read rightExpressed))
                  "negate" -> show (-(read leftExpressed))
                  "num"    -> read leftExpressed
                  "len"    -> show (length(leftExpressed))
                  "str"    -> read leftExpressed
                  "cat"    -> leftExpressed ++ rightExpressed


checkVariableExist :: AST -> Mapping -> String
checkVariableExist (ASTNode op EmptyAST EmptyAST) [] = op
checkVariableExist (ASTNode op EmptyAST EmptyAST) ((var_name,var_type,var_value):xs) = if op==var_name then var_value else checkVariableExist (ASTNode op EmptyAST EmptyAST) xs

checkVariableExist2 :: AST -> Mapping -> AST
checkVariableExist2 (ASTNode op EmptyAST EmptyAST) [] = (ASTNode op EmptyAST EmptyAST) 
checkVariableExist2 (ASTNode op EmptyAST EmptyAST) ((var_name,var_type,var_value):xs) = if op==var_name then (ASTNode var_type (ASTNode var_value EmptyAST EmptyAST) EmptyAST) else checkVariableExist2 (ASTNode op EmptyAST EmptyAST) xs
