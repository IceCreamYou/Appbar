<?php
// $Id$

/**
 * @file
 *   Allows choosing the Appbar identifier.
 */

/**
 * Sets up a form for choosing the Appbar identifier.
 */
class appbar_views_handler_filter_string_identifier extends views_handler_filter_many_to_one {
  function get_value_options() {
    $this->value_options = module_invoke_all('appbar_id');
  }
}
