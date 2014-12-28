(function ($) {

  $(document).bind('drupalOverlayLoad', function() {
  });

  $(document).on('click', function(event) {
    var $target = $(event.target);
    if ($target.is('a') && $target.parent().is('h2')) {
      var target = $target[0];
      var parents = $target.parents();
      var nids = [];
      $.each(parents, function(index, value) {
        var id = value.id;

        if (id.indexOf('node-') != -1 && id.match(/[0-9]/g)) {
          nids.push(value.id.replace(/\D/g, ''));
        }
      });

      nids.reverse();

      var nid = nids[0] || 0;

      var item = '(' + nid + ')';

      // Multiple values.
      var value = $('#edit-c4m-related-document-und', parent.window.document).val();
      if (value.indexOf(item) == -1) {
        value = value ? value + ', ' + item : item;
      }

      $('#edit-c4m-related-document-und', parent.window.document).val(value);
      $('#related-documents', parent.window.document).val(value);
      parent.Drupal.overlay.close();
    }


  });

})(jQuery);
