<?php

/**
 * @file
 *   Admin forms for the Appbar module.
 */

/**
 * Settings form.
 */
function appbar_admin(&$form_state) {
  $form['appbar_menu'] = array(
    '#type' => 'select',
    '#title' => t('Menu for appbar links'),
    '#description' => t('The first level of links from the menu chosen here will appear in the appbar.'),
    '#required' => TRUE,
    '#default_value' => variable_get('appbar_menu', 'secondary-links'),
    '#options' => menu_get_menus(),
  );
  $formats = filter_formats();
  foreach ($formats as $format) {
    $options[$format->format] = check_plain($format->name);
  }
  $form['appbar_filter'] = array(
    '#type' => 'select',
    '#title' => t('Input filter for alerts'),
    '#description' => t('This input filter will run over the text in alerts. Does not apply to hijacked system messages.'),
    '#required' => TRUE,
    '#default_value' => variable_get('appbar_filter', 1),
    '#options' => $options,
  );
  $form['appbar_hijack'] = array(
    '#type' => 'radios',
    '#title' => t('Hijack system messages for alerts'),
    '#required' => TRUE,
    '#default_value' => variable_get('appbar_hijack', 'yes-clear'),
    '#options' => array(
      'no' => t('Do not hijack system messages'),
      'yes-clear' => t('Use system message for alerts, and do not also show them above the content area'),
      'yes-no' => t('Use system messages for alerts, but also show them above the content area'),
    ),
  );
  return system_settings_form($form);
}