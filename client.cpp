/**
 * @file client.cpp
 * @author Sean Evans
 */

#include "client.hpp"
#include <stdlib.h>
#include <boost/bind.hpp>

namespace hw 
{
    
client::client( boost::asio::io_service& ioService, client_config const& client_config ) : 
    mIoService( ioService ),
    mClientConfig( client_config ),
    mResolver( mIoService ),
    mSocket( mIoService )
{
    mIoService.dispatch( boost::bind( &client::resolve, this ) );
}

client::~client()
{
}

void client::resolve( void )
{
    boost::asio::ip::tcp::resolver::query query( mClientConfig.getHostName(), mClientConfig.getServiceName() );
    mResolver.async_resolve( query, boost::bind( &client::resolveHandler, this, _1, _2 ) );
}

void client::resolveHandler( 
    const boost::system::error_code& error, boost::asio::ip::tcp::resolver::iterator iterator )
{
    if ( error ) {
        std::cerr << "DNS resolution failed: " << error << std::endl; 
        mIoService.stop();
        return;
    }

    mSocket.async_connect( iterator->endpoint(), boost::bind( &client::connectionHandler, this, _1 ) );
}

void client::connectionHandler( const boost::system::error_code& error )
{
    if ( error ) {
        std::cerr << "TCP connection failed: " << error << std::endl; 
        mIoService.stop();
        return;
    }

    // TODO: do something with the connection
    printf( "connected!\n" );
}

} /* namespace hw */

