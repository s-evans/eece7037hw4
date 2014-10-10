/**
 * @file version_command.hpp
 * @author Sean Evans
 */

#ifndef VERSION_COMMAND_H
#define VERSION_COMMAND_H

#include "command.hpp"
#include <string>

namespace hw 
{

class version_command :
    public command
{
public:

    /**
     * CTOR
     */
    version_command( unsigned int deviceId, std::string const& data );

    /**
     * DTOR
     */
    virtual ~version_command();

    /**
     * @brief Returns the command id of this type
     */
    static unsigned int sGetCommandId( void );

    /**
     * @brief Factory method
     */
    static version_command& sBuild( unsigned int deviceId, std::string const& data );

private:

    static const unsigned int sCommandId;

    /**
     * Hidden
     */
    version_command();

    /**
     * Hidden
     */
    version_command const& operator=( version_command const& );

    /**
     * Hidden
     */
    version_command( version_command const& );

};
    
} /* namespace hw */

#endif // VERSION_COMMAND_H

