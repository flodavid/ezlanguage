#pragma once

#include "../modules/Node.h"

enum ImportType { EXTERNAL_LIBRARY, LOCAL_FILE };

/**
 * @brief Node of the tree which represent a condition else
 */

class Import : public Node {

protected:
    std::string mHeaderName;
    ImportType mImportType;

public:
    /* * * * * * * * *
    * CONSTRUCTORS  *
    * * * * * * * * */

    /**
     * Constructor with parameters
     * @param left : left son
     */
    Import(const std::string & headerName, ImportType importType);

    /**
     * @brief destructor
     */
    virtual ~Import();


    /**
     * @brief Get the name of the node
     * @return the name of the node. Defined at class creation
     */
    virtual inline const std::string getName() const { return "Import"; }

    /* * * * * * * *
     * Translation *
     * * * * * * * */
    
    /**
     * @brief Translate the begining part of the If
     * @return a string containing the C++ code of the If
     *
     * All subclasses, should reimplement this method so that the translation corresponds
     * to their specifications, specificities and own values
     */
    virtual std::string preTranslate() const;

};
