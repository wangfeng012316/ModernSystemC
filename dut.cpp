/**
 * @file  dut.cpp
 * @brief Dut-level interconnect implementation
 */
#include "dut.hpp"
#include "sc_time_literals.hpp"
#include "processing.hpp"

using namespace sc_core;
using namespace sc_core::literals;

//..............................................................................
Dut_module::Dut_module( sc_module_name instance ) //< Constructor
: sc_module( instance )
  /**
   * Instantiate
   */
, process ( std::make_unique<Processing_module> ( "process" ) )
, clock   ( std::make_unique<sc_clock>          ( "clock", 10_ns ) )
{
  /**
   * Connect
   */
  process->input_port .bind( input_port       );
  process->output_port.bind( result_buffer    );
  process->clk_port   .bind( *clock           );
  out_xport           .bind( result_buffer    );
}

//..............................................................................
Dut_module::~Dut_module( void ) = default;
