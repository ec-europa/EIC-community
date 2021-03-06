<?php

/**
 * @file
 * Theme functions for the c4m_features_footer module.
 */

/**
 * Theme function for c4m footer block.
 *
 * @param array $variables
 *   Template variables.
 *
 * @return mixed
 *   Rendered output.
 */
function theme_c4m_footer_bar(array $variables) {

  if (c4m_og_is_of_group_type('project')) {
    // The template of the project page is different from the other pages on
    // the site (by design).
    return theme_c4m_footer_bar_project();
  }

  $output = '<ul class="c4m-footer-bar clearfix">';

  // Get c4m footer navigation links.
  $footer_navigation_1 = variable_get('c4m_footer_navigation_links_1');
  $footer_navigation_2 = variable_get('c4m_footer_navigation_links_2');

  $navigation_html_1 = '<ul class="ecl-list ecl-list--unstyled ecl-footer__list" aria-labelledby="footer-corporate-about-ec">';

  foreach ($footer_navigation_1 as $link) {
    $navigation_html_1 .= '<li class="ecl-footer__list-item">';
    $navigation_html_1 .= l(
      t('@title', array('@title' => $link['title'])),
      $link['url'],
      array('attributes' => $link['attributes'])
    );
    $navigation_html_1 .= '</li>';
  }
  $navigation_html_1 .= '</ul>';

  $navigation_html_2 = '<ul class="ecl-list ecl-list--unstyled ecl-footer__list" aria-labelledby="footer-corporate-about-eu">';
  foreach ($footer_navigation_2 as $link) {
    $navigation_html_2 .= '<li class="ecl-footer__list-item">';
    $navigation_html_2 .= l(
      t('@title', array('@title' => $link['title'])),
      $link['url'],
      array('attributes' => $link['attributes'], 'html' => TRUE)
    );
    $navigation_html_2 .= '</li>';
  }
  $navigation_html_2 .= '</ul>';


  // Get c4m social media.
  $footer_left_column =
  $social_media = variable_get('c4m_social_media');

  $variables = array(
    'left_column' => $navigation_html_1,
    'social_media' => theme_c4m_social_media($social_media),
    'right_column' => $navigation_html_2,
  );
  $output = theme('c4m_footer_bar_template', $variables);

  return $output;
}

/**
 * Theme function OG Project pages footer - uses project footer template.
 *
 * @return html
 *   Rendered html.
 */
function theme_c4m_footer_bar_project() {
  $options = array(
    'alias' => TRUE,
    'html' => TRUE,
    'attributes' => array(),
  );
  $europaid_link = l(
    t('DG International cooperation and development') . ' >',
    'https://ec.europa.eu/europeaid/home_en'
  );

  $options['attributes']['class'] = array('text-orange');
  $project_link = l(t('Capacity4dev') . ' >', '/projects', $options);

  $options['attributes']['title'] = t('Home');
  $options['attributes']['class'] = array('logo-project');
  $variables = array(
    'path' => (drupal_get_path('theme', 'kapablo') . '/project_logo.png'),
    'alt' => t('Home'),
    'attributes' => array(),
  );
  $logo_img = theme_image($variables);
  $logo_link = l($logo_img, '/', $options);

  $variables = array(
    'project_link' => $project_link,
    'logo_link' => $logo_link,
    'europaid_link' => $europaid_link,
  );
  $output = theme('c4m_footer_bar_project', $variables);

  return $output;
}

/**
 * Theme function for c4m footer block.
 *
 * @param array $variables
 *   Template variables.
 *
 * @return mixed
 *   Rendered output.
 */
function theme_c4m_footer_menu(array $variables) {
  $output = '<div class="c4m-footer-menu">';

  // Get c4m footer menu.
  $c4m_footer_menu = menu_tree('c4m-footer');
  $c4m_footer_menu['#theme_wrappers'] = array('menu_tree__small');
  $output .= render($c4m_footer_menu);

  $output .= '</div>';
  return $output;
}

/**
 * Theme function for c4m footer logo.
 *
 * @param array $variables
 *   Template variables.
 *
 * @return mixed
 *   Rendered output.
 */
function theme_c4m_footer_logo(array $variables) {
  global $base_url;

  $output = '<div class="c4m-footer-logo">';

  $logo_img = '<img src="' .
    $base_url . DIRECTORY_SEPARATOR . drupal_get_path(
      'theme',
      'kapablo'
    ) . DIRECTORY_SEPARATOR . 'footer.png" 
    alt="capacity4dev.eu" 
    title="capacity4dev.eu with hands" />';

  $output .= l($logo_img, '<front>', array('absolute' => TRUE, 'html' => TRUE));

  $output .= '</div>';
  return $output;
}

/**
 * Function to theme the social media links.
 *
 * @param array $social_media
 *   Array with the social media info.
 *
 * @return string
 *   Rendered html of social media.
 */
function theme_c4m_social_media(array $social_media) {
  $output = '<ul class="ecl-list ecl-list--unstyled ecl-list--inline 
      ecl-footer__list ecl-footer__list--inline  ecl-footer__social-links" 
      aria-labelledby="footer-corporate-social-media">
    <li class="c4m-social-media">';
  foreach ($social_media as $key => $link) {
    $link_classes = array('fa', 'fa-' . $key);
    $specific_link_classes = ['ecl-icon ecl-icon--facebook ecl-footer__social-icon'];
    $output .= '<div class="c4m-social-media-item c4m-social-media-' . $key . '">';
    $output .= l(
      t(
        '<i class="' . implode(
          $link_classes,
          ' '
        ) . '"></i><span>@title</span>',
        array('@title' => $link['title'])
      ),
      $link['url'],
      array(
        'html' => TRUE,
        'attributes' => array('target' => '_blank', 'classes' => array_merge($link_classes, $specific_link_classes)),
      )
    );
    $output .= '</div>';
  }
  $output .= '</li>';
  $output .= '</ul>';
  return $output;
}
