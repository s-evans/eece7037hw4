/**
 * @file command_factory.hpp
 * @author Sean Evans
 * @date 2014-10-10
 */

#ifndef COMMAND_FACTORY_H
#define COMMAND_FACTORY_H

#include "command.hpp"
#include <string>

namespace hw 
{
    
class command_factory 
{
public:

    /**
     * CTOR
     */
    command_factory( );

    /**
     * DTOR
     */
    virtual ~command_factory();

    /**
     * @brief Creates a command object based on the input string
     */
    virtual command& build( std::string const& str );

private:

    /**
     * Hidden
     */
    command_factory const& operator=( command_factory const& );

    /**
     * Hidden
     */
    command_factory( command_factory const& );

};

} /* namespace hw */

#endif // COMMAND_FACTORY_H

