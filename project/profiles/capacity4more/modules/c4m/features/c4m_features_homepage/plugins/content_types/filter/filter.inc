<?php

/**
 * @file
 * Content filter plugin.
 */

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Content Filter'),
  'description' => t('Renders Content Filter.'),
  'category' => t('C4M'),
);

/**
 * Render callback.
 *
 * @return object
 *   The block definition.
 */
function c4m_features_homepage_filter_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->module = 'c4m_features_homepage';
  $block->title = '';

  $block->content = drupal_get_form('c4m_features_homepage_filter_form_create');

  return $block;
}

/**
 * Create form element for homepage filter.
 *
 * @return mixed
 *   The element array.
 */
function c4m_features_homepage_filter_form_create() {
  $options = array();

  if (c4m_og_get_user_group_ids_by_bundle('group')) {
    $options['groups'] = t('My groups');
  }

  if (c4m_og_get_user_group_ids_by_bundle('project')) {
    $options['projects'] = t('My projects');
  }

  if (c4m_og_get_user_group_ids_by_bundle('event_site')) {
    $options['event_sites'] = t('My Event Sites');
  }

  if (c4m_og_get_user_group_ids_by_bundle('organisation')) {
    $options['organisations'] = t('My Organisations');
  }

  if (c4m_user_profile_get_interests()) {
    $options['interests'] = t('My interests');
  }

  // No options, show all anyway, hence we can drop this form.
  if (!$options) {
    return array();
  }

  $options['showAll'] = t('Show all');

  $get_query = drupal_get_query_parameters();
  $default_value = !empty($get_query['filter'])
    ? $get_query['filter']
    : 'showAll';

  if (!array_key_exists($default_value, $options)) {
    $default_value = 'showAll';
  }

  $form['homepage-filter'] = array(
    '#type' => 'radios',
    '#title' => t('Display content based on'),
    '#options' => $options,
    '#default_value' => $default_value,
  );

  $form['#attached']['js'][] = drupal_get_path('module', 'c4m_features_homepage') . '/plugins/content_types/filter/filter_homepage.js';

  $form['action'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => t('Filter'),
      '#id' => 'c4m_activity_stream_filter',
    ),
  );

  return $form;
}

/**
 * Edit form.
 *
 * @return array
 *   The form array.
 */
function c4m_features_homepage_filter_content_type_edit_form($form, &$form_state) {
  return $form;
}
