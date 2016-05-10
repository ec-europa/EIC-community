<?php
/**
 * @file
 * Custom Display Suite function fields.
 */

/**
 * DS function field.
 *
 * Render date on which user became C4M member.
 *
 * @param array $field
 *   The field information.
 *
 * @return mixed
 *   The rendered field output.
 */
function theme_c4m_user_member_since(array $field) {
  if (empty($field['entity'])) {
    return;
  }

  $tag['element'] = array(
    '#tag'       => 'span',
    '#attributes' => array(
      'class' => array('member-since'),
    ),
    '#value'     => c4m_helper_date_time_ago($field['entity']->created),
  );
  return theme_html_tag($tag);
}

/**
 * Render user activity summary.
 *
 * @param array $field
 *   Field information.
 *
 * @return mixed
 *   The rendered field output.
 */
function theme_c4m_user_activity_summary(array $field) {
  if (empty($field['entity'])) {
    return;
  }

  $user = $field['entity'];

  // Count published posts of user.
  $count_posts = c4m_user_count_nodes($user->uid);

  // Count published comments of user.
  $count_comments = c4m_user_count_comments($user->uid);

  // Format the string to show the number of posts/comments.
  $output = c4m_ds_user_activity_summary_helper($count_posts, $count_comments);
  return $output;
}

/**
 * Render count of posts (nodes) for the given user.
 *
 * @param array $field
 *   The field info.
 *
 * @return mixed
 *   The rendered field output.
 */
function theme_c4m_user_activity_posts(array $field) {
  if (empty($field['entity'])) {
    return;
  }

  $user = $field['entity'];

  // Count published posts of user.
  $count = c4m_user_count_nodes($user->uid);
  return format_plural($count, '1 Post', '@count Posts');
}

/**
 * Render count of comments for the given user.
 *
 * @param array $field
 *   The field info.
 *
 * @return mixed
 *   The rendered field output.
 */
function theme_c4m_user_activity_comments(array $field) {
  if (empty($field['entity'])) {
    return;
  }

  $user = $field['entity'];

  // Count published posts of user.
  $count = c4m_user_count_comments($user->uid);
  return format_plural($count, '1 Comment', '@count Comments');
}

/**
 * DS function field.
 *
 * Render ...
 *
 * @param array $field
 *   Field info.
 *
 * @return mixed
 *   Rendered data.
 */
function theme_c4m_user_picture(array $field) {
  if (empty($field['entity']->uid)) {
    return;
  }

  // Check if image needs to be linked to user profile.
  if (FALSE !== strpos($field['formatter'], 'linked_', 0)) {
    $linked = TRUE;
    $style = substr($field['formatter'], 7);
  }
  else {
    $linked = FALSE;
    $style = $field['formatter'];
  }

  // Check if this is a user or node entity.
  $user = 'user' === $field['entity_type'] ? $field['entity'] :
    user_load($field['entity']->uid);

  // Check if we have an image.
  $wrapper = entity_metadata_wrapper('user', $user);
  $file = $wrapper->c4m_media->value();

  if (empty($file)) {
    // If there is no image, we render initials.
    $output = c4m_user_initials_themed($user, $linked);
  }
  else {
    $file['style_name'] = empty($style) ? 'media_thumbnail' : $style;
    $file['path']       = $file['uri'];
    $file['attributes'] = array('class' => 'user-image');
    $output             = l(theme_image_style($file), 'user/' . $user->uid,
      array('html' => 'TRUE'));
  }

  return $output;
}

/**
 * DS function field.
 *
 * Render Author first and last name.
 *
 * @param array $field
 *   The field info.
 *
 * @return mixed
 *   The rendered field.
 */
function theme_c4m_user_first_and_last_name(array $field) {
  if (empty($field['entity'])) {
    return;
  }

  $output = '';
  $tag = array();
  $entity = $field['entity'];

  if ($entity->uid != 0) {
    $user     = user_load($entity->uid);
    $name     = c4m_user_name($user);
    $classes  = array();

    if (in_array($field['formatter'], array('linked_user', 'linked_user_with_icon'))) {
      $name = l($name, 'user/' . $user->uid);
    }

    $output .= $name;

    // Add organisation icon.
    if (in_array($field['formatter'], array('user_with_icon', 'linked_user_with_icon'))) {
      if (module_exists('c4m_content_organisation')) {
        $user_mail = $field['entity']->mail;
        $icon = c4m_content_organisation_get_icon_by_email($user_mail);
        if ($icon) {
          $classes[] = 'icon';
          $output .= '<div class="organisation-icon">' . render($icon) . '</div>';
        }
      }
    }

    $tag['element'] = array(
      '#tag'       => 'span',
      '#attributes' => array(
        'class' => array('user-name', implode(',', $classes)),
      ),
      '#value'     => $output,
    );
  }
  else {
    $entity_name = !empty($entity->name) ? $entity->name
                                         : variable_get('anonymous', t('Anonymous'));
    $tag['element'] = array(
      '#tag'       => 'span',
      '#attributes' => array(
        'class' => array('user-name', 'anonymous'),
      ),
      '#value'     => $entity_name,
    );
  }

  return theme_html_tag($tag);
}

/**
 * DS function field.
 *
 * Render ...
 *
 * @param array $field
 *   The field info.
 *
 * @return mixed
 *   The rendered output.
 */
function theme_c4m_user_country(array $field) {
  if (empty($field['entity']->uid)) {
    return;
  }

  // Check if this is a user or node entity.
  $user = 'user' === $field['entity_type'] ? $field['entity'] :
    user_load($field['entity']->uid);
  $allowed_values = &drupal_static(__FUNCTION__);
  if (empty($allowed_values)) {
    $field = field_info_field('c4m_country');
    $allowed_values = list_allowed_values($field);
  }
  // Check if we have an image.
  $wrapper = entity_metadata_wrapper('user', $user);
  $country = $allowed_values[$wrapper->c4m_country->value()];

  if (empty($country)) {
    return NULL;
  }
  if (t('- choose country or region -') === drupal_strtolower($country)) {
    return NULL;
  }

  // @codingStandardsIgnoreStart
  $value = t(ucwords(drupal_strtolower($country)));
  // @codingStandardsIgnoreEnd

  $tag['element'] = array(
    '#tag'       => 'span',
    '#attributes' => array(
      'class' => array('country'),
    ),
    '#value'     => $value,
  );
  return theme_html_tag($tag);
}

/**
 * Callback for c4m_user_contact_link DS field.
 *
 * @param array $field
 *   The field info.
 *
 * @return NULL|string
 *   The rendered output.
 *
 * @see _contact_personal_tab_access()
 */
function theme_c4m_user_contact_link(array $field) {
  global $user;

  $account = $field['entity'];

  // Anonymous users cannot have contact forms.
  if (!$account->uid) {
    return NULL;
  }

  // Users may not contact themselves.
  if ($user->uid == $account->uid) {
    return NULL;
  }

  // If the requested user has disabled their contact form, or this preference
  // has not yet been saved, do not allow users to contact them.
  if (empty($account->data['contact'])) {
    return NULL;
  }

  // If requested user has been blocked, do not allow users to contact them.
  if (empty($account->status)) {
    return NULL;
  }

  // User administrators should always have access to personal contact forms.
  if (user_access('administer users') || user_access('access user contact forms')) {
    return l(t('Contact this person'), "user/{$account->uid}/contact", array(
      'attributes' => array(
        'class' => array('btn', 'btn-default'),
      ),
    ));
  }
  else {
    return t('!register or !login to contact a member', array(
      '!register' => l(t('Register'), 'user/register'),
      '!login' => l(t('log in'), 'user/login'),
    ));
  }
}