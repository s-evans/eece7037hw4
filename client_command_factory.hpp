/**
 * @file client_command_factory.hpp
 * @author Sean Evans
 * @date 2014-10-10
 */

#ifndef CLIENT_COMMAND_FACTORY_H
#define CLIENT_COMMAND_FACTORY_H

#include "command.hpp"
#include "command_factory.hpp"
#include <map>

namespace hw 
{
    
class client_command_factory : 
    public command_factory
{
public:

    // Member types 
    typedef command& (*factory_fuction)( unsigned int deviceId, std::string const& data );
    typedef std::map<unsigned int, factory_fuction*> container_type;

    /**
     * CTOR
     */
    client_command_factory(  );

    /**
     * DTOR
     */
    virtual ~client_command_factory();

    /**
     * @brief Creates a command object based on the input string
     */
    virtual command& build( std::string const& str );

    /**
     * @brief Register a factory function and ID with the factory
     */
    void register_factory( unsigned int commandId, factory_fuction* function );

    /**
     * @brief Register a factory function 
     */
    template<typename T> void register_factory( void )
    {
        register_factory( T::sGetCommandId(), &T::sBuild );
    }

private:

    container_type mFactoryContainer;

    /**
     * Hidden
     */
    client_command_factory const& operator=( client_command_factory const& );

    /**
     * Hidden
     */
    client_command_factory( client_command_factory const& );

};

} /* namespace hw */

#endif // CLIENT_COMMAND_FACTORY_H

