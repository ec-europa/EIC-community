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
  $output = '<ul class="c4m-footer-bar clearfix">';

  // Get c4m footer navigation links.
  $footer_navigation_1 = variable_get('c4m_footer_navigation_links_1');
  $footer_navigation_2 = variable_get('c4m_footer_navigation_links_2');

  $navigation_html_1 = '<li class="c4m-footer-navigation-1 first">';
  foreach ($footer_navigation_1 as $link) {
    $navigation_html_1 .= '<div class="c4m-footer-nav-link">';
    $navigation_html_1 .= l(t('@title', array('@title' => $link['title'])),
                          $link['url'],
                          array('attributes' => $link['attributes'])
                        );
    $navigation_html_1 .= '</div>';
  }
  $navigation_html_1 .= '</li>';

  // Get c4m social media.
  $social_media = variable_get('c4m_social_media');
  $social_media_html = theme_c4m_social_media($social_media);

  $navigation_html_2 = '<li class="c4m-footer-navigation-2 last">';
  foreach ($footer_navigation_2 as $link) {
    $navigation_html_2 .= '<div class="c4m-footer-nav-link">';
    $navigation_html_2 .= l(t('@title', array('@title' => $link['title'])),
      $link['url'],
      array('attributes' => $link['attributes'], 'html' => true)
    );
    $navigation_html_2 .= '</div>';
  }
  $navigation_html_2 .= '</li>';

  // Output elements in correct order.
  $output .= $navigation_html_1;
  $output .= $social_media_html;
  $output .= $navigation_html_2;

  $output .= '</ul>';

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
 * Function to theme the social media links.
 *
 * @param array $social_media
 *    Array with the social media info.
 *
 * @return string
 *    Rendered html of social media.
 */
function theme_c4m_social_media(array $social_media) {
  $output = '<li class="c4m-social-media">';
  foreach ($social_media as $key => $link) {
    $link_classes = array('fa', 'fa-' . $key);
    $output .= '<div class="c4m-social-media-item c4m-social-media-' . $key . '">';
    $output .= l(t('<i class="' . implode($link_classes, ' ') . '"></i><span>@title</span>', array('@title' => $link['title'])), $link['url'],
                array('html' => TRUE, 'attributes' => array('target' => '_blank', 'classes' => $link_classes)));
    $output .= '</div>';
  }
  $output .= '</li>';

  return $output;
}