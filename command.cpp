/**
 * @file command.cpp
 * @author Sean Evans
 * @date 2014-10-10
 */

#include "command.hpp"
#include <sstream>

namespace hw 
{

const char* command::sFieldSeparator = ":";

command::command( unsigned int deviceId, unsigned int commandId, std::string const& data ) :
    mDeviceId( deviceId ),
    mCommandId( commandId ),
    mData( data )
{
}

command::~command()
{
}

std::string command::serialize( void )
{
    std::ostringstream oss;
    oss << getDeviceId() << sFieldSeparator << getCommandId() << sFieldSeparator << getData();
    return oss.str();
}

unsigned int command::getCommandId( void ) const
{
    return mCommandId;
}

unsigned int command::getDeviceId( void ) const
{
    return mDeviceId;
}

std::string const& command::getData( void ) const
{
    return mData;
}

} /* namespace hw */

