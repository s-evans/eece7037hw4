/**
 * @file main.cpp
 * @author Sean Evans
 * @date 2014-10-10
 */

#include <stdlib.h>
#include <boost/asio.hpp>
#include <boost/mem_fn.hpp>
#include "client.hpp"
#include "client_config.hpp"

/**
 * @brief Program entry point
 */
int main( int argc, const char* argv[] )
{
    // TODO: program options
    boost::asio::io_service io_service;
    // boost::asio::io_service::work work( io_service );

    hw::client_config config( "malware.eklipse.net", "9001" );
    hw::client client( io_service, config );

    io_service.run();

    return EXIT_SUCCESS;
}

