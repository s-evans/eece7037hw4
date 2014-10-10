/**
 * @file command_factory.cpp
 * @author Sean Evans
 */

#include "command_factory.hpp"
#include <sstream>
#include <stdexcept>

namespace hw
{

command_factory::command_factory()
{
}

command_factory::~command_factory()
{
}

command& command_factory::build( std::string const& str )
{
    std::istringstream oss( str );

    unsigned int deviceId;

    if ( !( oss >> deviceId ) ) {
        throw std::runtime_error( "failed to get device id" );
    }

    unsigned int commandId;

    if ( !( oss >> commandId ) ) {
        throw std::runtime_error( "failed to get command id" );
    }

    std::string data;

    if ( !( oss >> data ) ) {
        throw std::runtime_error( "failed to get data" );
    }

    return *new command( deviceId, commandId, data );
}

} /* namespace hw */

