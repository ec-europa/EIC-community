<?php
/**
 * @file
 * c4m_content_topic.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function c4m_content_topic_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|topic|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'topic';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|topic|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|topic|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'topic';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'activity_stream_by_topic' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'expert_users_by_topic' => array(
      'weight' => '8',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'related_articles_by_topic' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'related_events_by_topic' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'related_groups_by_topic' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'related_projects_by_topic' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_ds_topic_content_stats' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_vocab_topic_mapping' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Topics and Sub-Topics',
          'lb-el' => 'span',
          'lb-cl' => 'text-muted',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'topic-subtopics',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['node|topic|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|topic|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'topic';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h3',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'c4m_media' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
  );
  $export['node|topic|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function c4m_content_topic_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'activity_stream_by_topic';
  $ds_field->label = 'Activity Stream by Topic';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'topic|full';
  $ds_field->properties = array(
    'block' => 'views|c4m_related_content-block',
    'block_render' => '2',
  );
  $export['activity_stream_by_topic'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'expert_users_by_topic';
  $ds_field->label = 'Expert Users by Topic';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'topic|full';
  $ds_field->properties = array(
    'block' => 'views|c4m_expert_users-block',
    'block_render' => '2',
  );
  $export['expert_users_by_topic'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'related_articles_by_topic';
  $ds_field->label = 'Related Articles by Topic';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'topic|full';
  $ds_field->properties = array(
    'block' => 'views|c4m_related_nodes-block_2',
    'block_render' => '2',
  );
  $export['related_articles_by_topic'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'related_events_by_topic';
  $ds_field->label = 'Related Events by Topic';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'topic|full';
  $ds_field->properties = array(
    'block' => 'views|c4m_related_events-block',
    'block_render' => '2',
  );
  $export['related_events_by_topic'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'related_groups_by_topic';
  $ds_field->label = 'Related Groups by Topic';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'topic|full';
  $ds_field->properties = array(
    'block' => 'views|c4m_related_nodes-block',
    'block_render' => '2',
  );
  $export['related_groups_by_topic'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'related_projects_by_topic';
  $ds_field->label = 'Related Projects by Topic';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'topic|full';
  $ds_field->properties = array(
    'block' => 'views|c4m_related_nodes-block_1',
    'block_render' => '2',
  );
  $export['related_projects_by_topic'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function c4m_content_topic_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|topic|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'topic';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'c4m_vocab_theme',
        2 => 'c4m_vocab_topic_mapping',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'c4m_vocab_theme' => 'ds_content',
      'c4m_vocab_topic_mapping' => 'ds_content',
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
  );
  $export['node|topic|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|topic|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'topic';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'c4m_ds_8_4_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'c4m_ds_topic_content_stats',
        1 => 'c4m_banner',
        2 => 'c4m_header_meta',
        3 => 'c4m_vocab_topic_mapping',
        4 => 'title',
        5 => 'c4m_header_bottom',
        6 => 'c4m_body',
      ),
      'left' => array(
        7 => 'activity_stream_by_topic',
      ),
      'right' => array(
        8 => 'related_events_by_topic',
        9 => 'related_groups_by_topic',
        10 => 'related_projects_by_topic',
        11 => 'related_articles_by_topic',
        12 => 'expert_users_by_topic',
      ),
    ),
    'fields' => array(
      'c4m_ds_topic_content_stats' => 'header',
      'c4m_banner' => 'header',
      'c4m_header_meta' => 'header',
      'c4m_vocab_topic_mapping' => 'header',
      'title' => 'header',
      'c4m_header_bottom' => 'header',
      'c4m_body' => 'header',
      'activity_stream_by_topic' => 'left',
      'related_events_by_topic' => 'right',
      'related_groups_by_topic' => 'right',
      'related_projects_by_topic' => 'right',
      'related_articles_by_topic' => 'right',
      'expert_users_by_topic' => 'right',
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
    'hide_page_title' => '1',
    'page_option_title' => '',
  );
  $export['node|topic|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|topic|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'topic';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'c4m_media',
      ),
      'right' => array(
        1 => 'title',
      ),
    ),
    'fields' => array(
      'c4m_media' => 'left',
      'title' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['node|topic|teaser'] = $ds_layout;

  return $export;
}