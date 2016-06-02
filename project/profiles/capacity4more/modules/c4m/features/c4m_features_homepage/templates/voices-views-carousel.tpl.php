<?php
/**
 * @file
 * Prints out the Voices & Views carousel.
 */
?>

<div id="articles-panel">
  <div class="row carousel">
    <h3><?php print t('Latest Articles'); ?></h3>
    <div class="col-md-12">
      <div class="owl-carousel">
        <?php foreach ($carousels as $carousel): ?>
          <div class="item">
            <?php print $carousel['image']; ?>
            <h2><?php print $carousel['title']; ?></h2>
            <p class="intro-text"><?php print $carousel['text'] . ' | ' . $carousel['link']; ?></p>
          </div>
        <?php endforeach; ?>
      </div>
    </div>
  </div>

  <span class="block-title pull-right"><?php print l(t('Read more articles >'), 'articles'); ?></span>
</div>