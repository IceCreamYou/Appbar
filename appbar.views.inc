<?php
// $Id$

/**
 * @file
 * Provide views data and handlers for the Application Toolbar module.
 */

/**
 * Implementation of hook_views_data().
 */
function appbar_views_data() {
  //Basic table information.
  $data['appbar']['table']['group']  = t('Application Toolbar');
  $data['appbar']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid',
      'type' => 'INNER',
    ),
  );
  $data['users']['table']['join'] = array(
    'appbar' => array(
      'left_field' => 'uid',
      'field' => 'uid',
    ),
  );

  //Advertise this table as a possible base table.
  $data['appbar']['table']['base'] = array(
    'field' => 'uid',
    'title' => t('Application Toolbar Alerts'),
    'help' => t('Appbar alert listings.'),
    'weight' => 10,
  );

  $data['appbar']['tid'] = array(
    'title' => t('Alert ID'),
    'help' => t('The ID of the Appbar alert.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  $data['appbar']['uid'] = array(
    'title' => t('User ID'),
    'help' => t('The User ID of the user to whom the alert should be shown.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  $data['appbar']['status'] = array(
    'title' => t('Read status'),
    'help' => t('The read/unread status of the message. 1 is unread, 0 is read'),
    'field' => array(
      'handler' => 'appbar_views_handler_field_read',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  $data['appbar']['alert_time'] = array(
    'title' => t('Alert time'),
    'help' => t('The time the alert was recorded.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  $data['appbar']['message'] = array(
    'title' => t('Alert message'),
    'help' => t('The text of the alert message.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
  );
  
  $data['appbar']['identifier'] = array(
    'title' => t('Alert type'),
    'help' => t('The type of action that was recorded.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  return $data;
}

/**
 * Implementation of hook_views_data_alter().
 */
function appbar_views_data_alter(&$data) {
  $data['appbar']['users'] = array(
    'group' => t('Application Toolbar'),
    'relationship' => array(
      'title' => t('Users'),
      'label' => t('Users'),
      'help' => t('Gain access to information about the user who will see the alerts.'),
      'relationship table' => 'users',
      'relationship field' => 'uid',
      'base' => 'appbar',
      'field' => 'uid',
      'type' => 'INNER',
      'handler' => 'views_handler_relationship',
    ),
  );
}

/**
 * Implementation of hook_views_handlers().
 */
function appbar_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'appbar'),
    ),
    'handlers' => array(
      'appbar_views_handler_field_read' => array(
        'parent' => 'views_handler_field',
      ),
    ),
  );
}