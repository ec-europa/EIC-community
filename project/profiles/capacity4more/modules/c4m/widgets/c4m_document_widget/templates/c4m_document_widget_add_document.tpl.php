<?php

/**
 * @file
 * Template to render the upload new document widget.
 */
?>
<div ng-controller="<?php print $ctrl; ?>">

  <form name="documentForm" action="overlay-file/<?php print $file_id; ?>?render=overlay" ng-submit="createDocument($event, '<?php print $file_id; ?>', data, addToLibrary)">

    <?php print t('Upload new document:'); ?>
    <br/>
    <?php print $file; ?>

    <br/>
    <label class="control-label" for="edit-title" title="Title">Title <span class="form-required" title="This field is required.">*</span></label>
    <input id="label" class="form-control" name="label" type="text" placeholder="<?php print t('Add document title'); ?>"
           title="<?php print t('Add document title'); ?>" ng-minlength=3 ng-model="data.label" required>
    <br/>
    <p>Add this document also to the group Library?</p>
    <button type="submit" id="save-edit" ng-click="addToLibrary = true" class="btn btn-primary" tabindex="100" title="Save and add to the group library"><?php print t('YES'); ?></button>
    <button type="submit" id="save" ng-click="addToLibrary = false" class="btn btn-primary" tabindex="100" title="Save and do not add to the group library"><?php print t('NO'); ?></button>
    <a href="javascript://" id="clear-button" ng-click="closeOverlay()" title="Cancel"><?php print t('Cancel'); ?></a>
  </form>
</div>
