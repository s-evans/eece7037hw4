/**
 * @file client_config.hpp
 * @author 
 */

#ifndef CLIENT_CONFIG_H
#define CLIENT_CONFIG_H

#include <string>

namespace hw 
{
    
class client_config 
{
public:

    /**
     * CTOR
     */
    client_config( std::string const& hostName, std::string const& serviceName );

    /**
     * DTOR
     */
    ~client_config();

    /**
     * @brief getter method
     */
    std::string const& getHostName( void ) const;

    /**
     * @brief getter method
     */
    std::string const& getServiceName( void ) const;

private:

    std::string mHostName;
    std::string mServiceName;

    /**
     * Hidden
     */
    client_config();

    /**
     * Hidden
     */
    client_config const& operator=( client_config const& );

    /**
     * Hidden
     */
    client_config( client_config const& );

};

} /* namespace hw */

#endif // CLIENT_CONFIG_H

