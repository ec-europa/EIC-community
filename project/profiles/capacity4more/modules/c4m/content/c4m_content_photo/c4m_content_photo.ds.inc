<?php
/**
 * @file
 * c4m_content_photo.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function c4m_content_photo_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|photo|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'photo';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '18',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_media' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|photo|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|photo|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'photo';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'c4m_media' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
  );
  $export['node|photo|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|photo|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'photo';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_field_og_group' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_ds_submitted_by_and_on' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'j F Y',
    ),
    'c4m_media' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|photo|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|photo|teaser_group';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'photo';
  $ds_fieldsetting->view_mode = 'teaser_group';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_ds_submitted_by_and_on' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'j F Y',
    ),
    'c4m_media' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|photo|teaser_group'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function c4m_content_photo_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'comment|comment_node_photo|activity_global';
  $ds_layout->entity_type = 'comment';
  $ds_layout->bundle = 'comment_node_photo';
  $ds_layout->view_mode = 'activity_global';
  $ds_layout->layout = 'ds_reset';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'comment_body',
      ),
    ),
    'fields' => array(
      'comment_body' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['comment|comment_node_photo|activity_global'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'comment|comment_node_photo|activity_group';
  $ds_layout->entity_type = 'comment';
  $ds_layout->bundle = 'comment_node_photo';
  $ds_layout->view_mode = 'activity_group';
  $ds_layout->layout = 'ds_reset';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'comment_body',
      ),
    ),
    'fields' => array(
      'comment_body' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['comment|comment_node_photo|activity_group'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|photo|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'photo';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'c4m_ds_8_4_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'c4m_media',
      ),
      'right' => array(
        1 => 'c4m_body',
        2 => 'node_gallery_navigation',
      ),
      'header' => array(
        3 => 'title',
      ),
    ),
    'fields' => array(
      'c4m_media' => 'left',
      'c4m_body' => 'right',
      'node_gallery_navigation' => 'right',
      'title' => 'header',
    ),
    'classes' => array(),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|photo|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|photo|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'photo';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'node_gallery_navigation',
        1 => 'c4m_media',
        2 => 'c4m_body',
      ),
    ),
    'fields' => array(
      'node_gallery_navigation' => 'ds_content',
      'c4m_media' => 'ds_content',
      'c4m_body' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
    'hide_page_title' => '0',
    'page_option_title' => '',
  );
  $export['node|photo|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|photo|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'photo';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'c4m_ds_4_8_fluid_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'c4m_media',
      ),
      'right' => array(
        1 => 'title',
        2 => 'c4m_ds_submitted_by_and_on',
        3 => 'c4m_field_og_group',
        4 => 'c4m_body',
      ),
    ),
    'fields' => array(
      'c4m_media' => 'left',
      'title' => 'right',
      'c4m_ds_submitted_by_and_on' => 'right',
      'c4m_field_og_group' => 'right',
      'c4m_body' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|photo|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|photo|teaser_group';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'photo';
  $ds_layout->view_mode = 'teaser_group';
  $ds_layout->layout = 'c4m_ds_4_8_fluid_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'right' => array(
        0 => 'c4m_ds_submitted_by_and_on',
        1 => 'title',
        3 => 'c4m_body',
      ),
      'left' => array(
        2 => 'c4m_media',
      ),
    ),
    'fields' => array(
      'c4m_ds_submitted_by_and_on' => 'right',
      'title' => 'right',
      'c4m_media' => 'left',
      'c4m_body' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|photo|teaser_group'] = $ds_layout;

  return $export;
}