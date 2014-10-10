/**
 * @file client_config.cpp
 * @author Sean Evans
 */

#include "client_config.hpp"

namespace hw 
{

client_config::client_config( std::string const& hostName, std::string const& serviceName ) :
    mHostName( hostName ),
    mServiceName( serviceName )
{
}

client_config::~client_config()
{
}

std::string const& client_config::getHostName( void ) const
{
    return mHostName;
}

std::string const& client_config::getServiceName( void ) const
{
    return mServiceName;
}

} /* namespace hw */

