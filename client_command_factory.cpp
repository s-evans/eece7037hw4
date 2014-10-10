/**
 * @file client_command_factory.cpp
 * @author
 */

#include "client_command_factory.hpp"
#include <memory>
#include <stdexcept>

namespace hw
{

client_command_factory::client_command_factory()
{
}

client_command_factory::~client_command_factory()
{
}

command& client_command_factory::build( std::string const& str )
{
    std::auto_ptr<command> pCommand( &command_factory::build( str ) );
    container_type::iterator it = mFactoryContainer.find( pCommand->getDeviceId() );
    if ( it == mFactoryContainer.end() ) {
        throw std::runtime_error("unhandled command id");
    }
    return (*it->second)( pCommand->getDeviceId(), pCommand->getData() );
}

void client_command_factory::register_factory( unsigned int commandId, factory_fuction* function )
{
    container_type::iterator it = mFactoryContainer.lower_bound( commandId );

    if ( it != mFactoryContainer.end() && mFactoryContainer.key_comp()( commandId, it->first ) ) {
        it->second = function;
    } else {
        mFactoryContainer.insert( it, container_type::value_type( commandId, function ) );
    }
}

} /* namespace hw */

