#pragma once

#include "../Instruction.h"
#include "../../modules/Expression.h"
#include "../../modules/Operator.h"

enum StringFunctionName {
    LENGTH, TOUPPERCASE, TOLOWERCASE, SUBSTRING_1, SUBSTRING_2, SPLIT, STRIP_1,
    STRIP_2, REPLACE, CONTAINS, FIND, FINDFIRSTOF, FINDLASTOF
}

/**
 * @brief Node of the tree which represent a condition else
 */

class StringFunction : public Instruction {

protected:
    StringFunctionName mFunctionName;
    int mFirstArg;
    int mSecondArg;
    int nbArgs;
	
public:
    /* * * * * * * * *
    * CONSTRUCTORS  *
    * * * * * * * * */

    /**
     * Constructor for zero parameters functions
     */
    StringFunction(StringFunctionName functionName);
    
    /**
     * Constructor for one integer parameter functions
     */
    StringFunction(StringFunctionName functionName, int intArg);
    
    /**
     * Constructor for two integer parameters functions
     */
    StringFunction(StringFunctionName functionName, int firstArg, int secondArg);
        
  objectDotOperator LENGTH LEFT_PARENTHESIS RIGHT_PARENTHESIS { printf("lENGTH() called \n"); }
| objectDotOperator TOUPPERCASE LEFT_PARENTHESIS RIGHT_PARENTHESIS { printf("toUpperCase() called \n"); }
| objectDotOperator TOLOWERCASE LEFT_PARENTHESIS RIGHT_PARENTHESIS { printf("toLowerCase() called \n"); }
| objectDotOperator SUBSTRING LEFT_PARENTHESIS integerExpression RIGHT_PARENTHESIS { printf("SUBSTRING(int) called \n"); }
| objectDotOperator SUBSTRING LEFT_PARENTHESIS integerExpression COMMA integerExpression RIGHT_PARENTHESIS { printf("SUBSTRING(int,int) called \n"); }
| objectDotOperator SPLIT LEFT_PARENTHESIS STRING RIGHT_PARENTHESIS { printf("SPLIT(\"str\") called \n"); }
| objectDotOperator STRIP LEFT_PARENTHESIS RIGHT_PARENTHESIS { printf("strip() called \n"); }
| objectDotOperator STRIP LEFT_PARENTHESIS STRING RIGHT_PARENTHESIS { printf("strip(\"str\") called \n"); }
| objectDotOperator REPLACE LEFT_PARENTHESIS STRING COMMA STRING RIGHT_PARENTHESIS { printf("replace(\"str\",\"str\") called \n"); }
| objectDotOperator CONTAINS LEFT_PARENTHESIS STRING RIGHT_PARENTHESIS { printf("contain(\"str\") called \n"); }
| objectDotOperator FIND LEFT_PARENTHESIS STRING RIGHT_PARENTHESIS { printf("find(\"str\") called \n"); }
| objectDotOperator FINDFIRSTOF LEFT_PARENTHESIS STRING RIGHT_PARENTHESIS { printf("findFirstOF(\"str\") called \n"); }
| objectDotOperator FINDLASTOF LEFT_PARENTHESIS STRING RIGHT_PARENTHESIS { printf("findFirstOF(\"str\") called \n"); }
;

}