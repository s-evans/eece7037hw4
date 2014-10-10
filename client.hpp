/**
 * @file client.hpp
 * @author Sean Evans
 */

#ifndef CLIENT_H
#define CLIENT_H

#include <boost/asio.hpp>
#include "client_config.hpp"

namespace hw 
{
    
class client 
{
public:

    /**
     * CTOR
     */
    client( boost::asio::io_service& ioService, client_config const& client_config );

    /**
     * DTOR
     */
    ~client();

private:

    boost::asio::io_service& mIoService;
    const client_config&     mClientConfig;
    boost::asio::ip::tcp::resolver mResolver;
    boost::asio::ip::tcp::socket mSocket;

    /**
     * @brief Starts dns resolution
     */
    void resolve( void );

    /**
     * @brief Handles dns resolution
     */
    void resolveHandler( 
        const boost::system::error_code& error, boost::asio::ip::tcp::resolver::iterator iterator );

    /**
     * @brief Handles tcp connection
     */
    void connectionHandler( const boost::system::error_code& error );

    /**
     * Hidden
     */
    client();

    /**
     * Hidden
     */
    client const& operator=( client const& );

    /**
     * Hidden
     */
    client( client const& );

};

} /* namespace hw */

#endif // CLIENT_H

